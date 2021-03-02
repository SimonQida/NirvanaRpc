#include "../testinlcude.h"
#include "protocol/jsonProtocol.h"

using nirvana::protocol::jsonProtocol;
class request{
    string xx;
};

class response{
    string result;
};

/*
response callRpc(request x){
    
}

Nprotocol np(transportSharedPtr);

string tmp;
np.readMessageBegin(tmp);
np.readMessageEnd();

np.readFieldBegin(tmp);
np.readFieldEnd();
if (tmp == "result"){
    np.readString(tmp);
    resp.result = tmp;
}
*/

shared_ptr<NBuffertransport> buildServerSocketTransport(){
    shared_ptr<NServerSocket> ns (new NServerSocket("127.0.0.1", 11234));
    if(ns->bind() == 0){
        cout<<"bind failed: "<<strerror(errno)<<endl;
        return 0;
    }

    if(ns->listen(10) == 0){
        cout<<"listen failed: "<<strerror(errno)<<endl;
        return 0;
    }

    //one line
    struct sockaddr sa;
    socklen_t socklen;
    int fd = ns->accept(&sa, &socklen);
    shared_ptr<NioSocket> spNio(new NioSocket(fd));
    return shared_ptr<NBuffertransport> (new NBuffertransport(spNio));
}

int main(){
    logging::log* logger = logging::log::getLogger();
    logger->setLevel(DEBUG);
    auto x = buildServerSocketTransport();
    string tmp;

    shared_ptr<NBuffertransport> NBt(x);
    jsonProtocol readJp(NBt);
    readJp.readMessageBegin(tmp);
    readJp.readMessageEnd();
    cout<<" remote call method name"<<tmp<<endl;
    const char* firstKey = "HeloWord";
    readJp.readFieldBegin(firstKey);
    
    string request ;
    readJp.readString(request);
    cout<<fmt::format("{} content is: ", firstKey)<<request<<endl;
    readJp.readFieldEnd();

    //functional behavior
    int response = request.size();
    readJp.writeMessageBegin("response");
    readJp.writeMessageEnd();

    readJp.writeFieldBegin("code");
    readJp.writeInt(0);
    readJp.writeFieldEnd();

    readJp.writeFieldBegin("message");
    readJp.writeString("ok");
    readJp.writeFieldEnd();

    readJp.writeFieldBegin("data");
    readJp.writeInt(response);
    readJp.writeFieldEnd();

    readJp.writeFlush();
    //logger->info("exit");
}
