#include "transport/csocket.h"
#include "transport/socketBase.h"
#include<iostream>
#include<memory>
#include<sys/select.h>

using nirvana::socket::NServerSocket;
using nirvana::socket::NioSocket;
using namespace std;

//server point
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
    shared_ptr<NioSocket> rw (new NioSocket(fd));
    cout<<"set io fd non-block result: " << rw->setNonBlock()<<endl;
    string buf;
    const int pageSize = 100;
    int ret;
    while(1){
        ret = rw->read(buf, pageSize);
        if(ret != -1)
            break;
    }

    cout<<"read data from socket: size: "<<ret<<", data : "<<buf<<endl;
    string response = "response the message :fuck you ";
    rw->write(response, response.size());
    cout<<"talk done ~"<<endl;
}
