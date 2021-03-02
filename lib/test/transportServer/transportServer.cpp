#include "../testinlcude.h"

int fromWire32(const char* wireData ){
    int res = 0;
    int mod = 0x00ff;
    for (int i =3; i >= 0; --i){
        res += ((int)wireData[i] & mod) << (8 * i);
        cout<<fmt::format("index i = {}, number = {}, current res = {}", i, int(wireData[i]), res)<<endl;
    }
    return res;
}

int main(){
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
    NBuffertransport bufTrans(shared_ptr<NioSocket> (new NioSocket(fd)));

    string buf;
    const int pageSize = 14;
    int ret = bufTrans.read(buf, pageSize);
    cout<<"read data from socket: size: "<<ret<<", data : "<<buf<<endl;
    string response = "response the message :fuck you ";
    bufTrans.write(response);
    bufTrans.writeFlush();
    string tmp;
    ret = bufTrans.read(tmp, 4);
    cout<<"read data from socket: size: "<<ret<<", data : "<<tmp<<endl;
    cout<<fromWire32(tmp.c_str());
    cout<<"talk done ~"<<endl;
}
