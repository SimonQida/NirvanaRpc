#include "bufferTransport.h"
#include "logging.h"
#include "utils/utils.h"

using namespace nirvana::transport;
using namespace nirvana::Nio;
using namespace std;
using namespace logging;
using namespace nirvana::utils;
/*
constexpr auto DEBUG = DEBUG;
constexpr auto INFO= INFO;
constexpr auto WARNING = WARNING;
constexpr auto ERROR = ERROR;
constexpr auto CRITICAL = CRITICAL;
*/

NBufTException::NBufTException(){ }

NBufTException::NBufTException(string err): errmsg(err){ }

const char* NBufTException::what()const noexcept{
    return errmsg.c_str();
}

NBuffertransport::NBuffertransport(shared_ptr<NioBase> fd, const string& logHeader):Ntransport(fd),logName(logHeader){
    reset();
    bufferLog = log::getLogger();
    logPrint(fmt::format("NBuffertransport build a {}" ,"logHeader"));
};

NBuffertransport::~NBuffertransport(){
    //writeFlush();
    //readFlush();
}

void NBuffertransport::reset(){
    wCur= rBegin = rEnd = 0;
}

int NBuffertransport::isClear()const{
    return wCur+rBegin+rEnd ;
}

int NBuffertransport::writeSlow(const char* data, int size){
    int resSize = transportFd.get()->write(data, size);
    logPrint(fmt::format("NBuffertransport writeSlow: require write size: {}, require write data stream :[({})], real write to pipe size {}"\
     , to_string(size), printBuf(data, size), to_string(resSize)), DEBUG);
    return resSize;
}

int NBuffertransport::readSlow(string& data, int size){
    int resSize = transportFd.get()->read(data, size);
    logPrint(fmt::format("NBuffertransport readSlow: require read size: {}, has read data stream :[({})], the size from pipe we get :{}"\
     , to_string(size), printBuf(data, resSize), to_string(resSize)), DEBUG);
    return resSize;
}

int NBuffertransport::write(const char* buf,int len){
    if(len >= bufSize){
        writeFlush();
        return writeSlow(buf, len);
    }

    if (wCur + len > bufSize){
        writeFlush();
    }
    memcpy(writeBuf + wCur, buf, len);
    wCur += len;
    return len;
}

int NBuffertransport::write(const string& data){
    return write(data.c_str(), data.size());
}

void NBuffertransport::logPrint(const string& logMsg, const logLevel& ll)const{
    string title = "{" + logName + "}: ";
    bufferLog->print(title + logMsg, ll);
    return;
}

int NBuffertransport::read(char* buf, int len){
    return 0;
}

int NBuffertransport::read(string& data, int len){
    data.clear();
    int curSize, loopTime =0;
    logPrint(fmt::format("NBuffertransport req-read-len: {}, now we loop to fetch all the required dagta", len), DEBUG);
    // if the up layer read a string , it shall alway declare the string size
    while(len){
        // bufleft size less than require-data size, fullfill
        ++loopTime;
        if(rEnd - rBegin < len){
            if(!readFlush()) return -1;
        }

        curSize = rEnd - rBegin < len ? rEnd - rBegin : len;
        data += readFromRbuf(curSize);
        len -= curSize;
        logPrint(fmt::format("NBuffertransport read loop {},collecting data: current data string: {}, current left len to read: {}"\
                , loopTime, printBuf(data, data.size()), data.size()), DEBUG);
        if(len < 0){
            logPrint("NBuffertransport required len being less than 0 strangly while len looping to decrease to read data, current len: ["+ to_string(len) + "]", ERROR);
            throw NBufTException("read len less than zero while looping");
        }
    }
    reportCursor(INFO);
    logPrint("NBuffertransport read data :[" + data+ "], data len: " + to_string(data.size()));
    return data.size();
}

void NBuffertransport::writeToRbuf(const string& stream){
    if(stream.size() > bufSize - (rEnd-rBegin)){
        logPrint("NBuffertransport writeToRbuf failed: be-writen size larger than free space", ERROR);
        throw NBufTException("writeToRbuf length over the bufSize");
    }

    if(stream.size() > bufSize - bufMap(rEnd)){
        int toEndSize = bufSize - bufMap(rEnd);
        memcpy(readBuf + bufMap(rEnd), stream.c_str(),
                toEndSize);
        memcpy(readBuf, stream.c_str()+ toEndSize,
                stream.size() - toEndSize);
    }
    else{
        memcpy(readBuf + bufMap(rEnd), stream.c_str(), stream.size());
    }
    logPrint(fmt::format("NBuffertransport readbuf updated by writeToRbuf: plus data {}\n\tcurrent readbuf content: {}"\
     , printBuf(stream, stream.size()), printBuf(readBuf, bufSize)), DEBUG);
}

void NBuffertransport::reportCursor(const logLevel& ll)const{
    logPrint("current wCur: [" + to_string(wCur) + "], rBegin: [" +\
            to_string(rBegin) + "], rEnd: [" + to_string(rEnd) + "]", ll);
}

string NBuffertransport::readFromRbuf(int size){
    string resStr;

    if(size > rEnd - rBegin){
        reportCursor();
        logPrint("NBuffertransport readFromRbuf: requireSize: " + \
                to_string(size) + " ,current left size: " + to_string(rEnd - rBegin), ERROR);
        throw NBufTException("read data from rbuf: required more");
    }

    if(size > bufSize - bufMap(rBegin)){
        int toEndSize = bufSize - bufMap(rBegin);
        resStr = string(readBuf + bufMap(rBegin), toEndSize);
        resStr += string(readBuf, size - toEndSize);
    }
    else{
        resStr = string(readBuf + bufMap(rBegin), size);
    }
    rBegin += size;
    return resStr;
}

// map the number-cursor to physical-cursor, if overflow then
// reset the cursor and the buffer data
int NBuffertransport::bufMap(int origin){
    if(origin < 0) throw 2;
    return origin % bufSize;
}

void NBuffertransport::writeFlush(){
    writeSlow(writeBuf, wCur);
    wCur = 0;
}

void NBuffertransport::rebuf(){
    if(rEnd == rBegin){
        rEnd = rBegin = 0;
        return ;
    }
    string reStr;
    if(bufMap(rEnd) <= bufMap(rBegin)){
        reStr += string(readBuf + bufMap(rBegin), bufSize - bufMap(rBegin));
        reStr += string(readBuf, bufMap(rEnd));
    }
    else{
        reStr += string(readBuf + bufMap(rBegin), 
                rEnd - rBegin);
    }
    
    //put the left data to new position place when rebuf 
    rEnd = rEnd - rBegin + 0;
    rBegin  = 0;
    memcpy(readBuf, reStr.c_str(), rEnd);
}

bool NBuffertransport::readFlush(){
    // fullfill the buf unless not enough data in socket
    int rSize = 0, requireSize = bufSize - (rEnd - rBegin);
    string tmpStr;
    rSize = readSlow(tmpStr, requireSize);
    if(rSize == 0 && requireSize != 0){
        streamDry = 1;
        return false;
    }
    
    if(rEnd + rSize < 0)
        rebuf();
    
    writeToRbuf(tmpStr);
    rEnd += rSize;

    return true;
}
