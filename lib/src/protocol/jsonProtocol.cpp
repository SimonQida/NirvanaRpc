#include "jsonProtocol.h"
#include <iostream>

using namespace logging;
using namespace nirvana::protocol;
using namespace nirvana::transport;

int fromWire32(string& wiredata ){
    //std::cout<<"str :"<<std::hex<<int(wiredata[0])<<" "<<int(wiredata[1])<< " "<<int(wiredata[2])<< " "<<int(wiredata[3])<<std::endl;
    int res = 0;
    int mod = 0x00ff;
    for (int i =3; i >= 0; --i){
        res += ((int)wiredata[i] & mod) << (8 * i);
    }
    return res;
}

jsonProtocol::jsonProtocol(shared_ptr<Ntransport> transFd):Nprotocol(transFd){
    protoLog->info(fmt::format("jsonProtocol tunnel built :"));
}

ssize_t jsonProtocol::readMessageBegin(string& buf){
    protoLog->info(fmt::format("readMessage Begin:"));
    readFlush();
    buf = readJson["rpcMethod"];
    protoLog->info(fmt::format("readMessage this rpcMethod name: {}", buf));
    return buf.size();
}

ssize_t jsonProtocol::readMessageEnd(){
    protoLog->info(fmt::format("readMessage End"));
}

ssize_t jsonProtocol::readFieldBegin(const string& fieldName){
    readFieldName = fieldName;
    protoLog->debug(fmt::format("readField {} from readJson, let readFieldName to {}",\
                fieldName, readFieldName));
    return 0;
}

ssize_t jsonProtocol::readFieldEnd(){
    protoLog->debug(fmt::format("readField {} from readJson done", readFieldName));
    readFieldName.clear();
}

ssize_t jsonProtocol::readString(string& buf){
    buf = readJson[readFieldName];
    protoLog->debug(fmt::format("\treadField {}, we get {}", readFieldName, buf));
    return buf.size();
}

ssize_t jsonProtocol::readInt(int& number){
    number = readJson[readFieldName];
    protoLog->debug(fmt::format("\treadField {}, we get {}", readFieldName, number));
    return 4;
}

ssize_t jsonProtocol::readFlush(){
    readJson.clear();
    //first read a datalen, and read a string length datalen
    string lenStr;
    tran_->read(lenStr, 4);
    int jsonStrLen = fromWire32(lenStr);
    protoLog->info(fmt::format("this time we fetch {} char from socket", jsonStrLen));
    string buf;
    tran_->read(buf, jsonStrLen);
    readJson = json::parse(buf);
    protoLog->info(fmt::format("read one json line: jsonStr is {}, jsondata is {}",\
                buf, readJson.dump(4)));
}

ssize_t jsonProtocol::writeMessageBegin(const string& buf){
// log in every write or read
// set log level in CMake options
    writeJson["rpcMethod"] = buf;
}

ssize_t jsonProtocol::writeMessageEnd(){
}

ssize_t jsonProtocol::writeFieldBegin(const string& buf){
    if (writeFieldName.size()){
        string message = fmt::format("Field title name conflict,"
                    " original name: {}, field write by: {}", writeFieldName, buf);
        protoLog->print(message, ERROR);
        throw NProtocolException(message);
    }

    writeFieldName = buf;
}

ssize_t jsonProtocol::writeFieldEnd(){
    writeFieldName.clear();
}

ssize_t jsonProtocol::writeInt(const int& number){
    checkFieldNameExit();
    writeJson[writeFieldName] = number;
    protoLog->debug(fmt::format("write field name {}, write field value {}", writeFieldName, number));
}

void jsonProtocol::checkFieldNameExit()const{
    if(!writeFieldName.size()){
        string message = fmt::format("fetch title name failed,"
                    " no field name when writing value");
        protoLog->print(message, ERROR);
        throw NProtocolException(message);
    }
}

ssize_t jsonProtocol::writeString(const string& buf){
    checkFieldNameExit();
    writeJson[writeFieldName] = buf;
    protoLog->debug(fmt::format("write field name {}, write field value {}", writeFieldName, buf));
}

void toWire32(char* wireData, int number){
    int mod = 0x00ff;
    for (int i =0; i < sizeof(number); ++i){
        wireData[i] = mod &number;
        number >>= 8;
    }
    //std::cout<<fmt::format("int data, {}, {}, {}, {}",int(wireData[0]), int(wireData[1]), int(wireData[2]), int(wireData[3]))<<std::endl;;
    //protoLog->info();
}

ssize_t jsonProtocol::writeFlush(){
    // write a datalen and then the datalen-length jsonString
    string jsonStr = writeJson.dump();
    int jsonLen = jsonStr.size();
    protoLog->info(fmt::format("jsonStr: {}, jsonLen: {}", writeJson.dump(4), jsonLen));

    char firstLen[4];
    toWire32(firstLen, jsonLen);
    tran_->write(firstLen, 4);
    tran_->write(jsonStr);
    tran_->writeFlush();
    writeJson.clear();
}

