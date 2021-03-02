#include "transport/csocket.h"
#include "transport/socketBase.h"
#include<iostream>
#include<memory>
#include<sys/select.h>
#include<errno.h>
#include<fmt/core.h>

using nirvana::socket::NServerSocket;
using nirvana::socket::NioSocket;
using namespace std;

const int pageSize = 100;
void keepQuery(shared_ptr<NServerSocket> ns){
    //one line
    struct sockaddr sa;
    socklen_t socklen;
    int fd = ns->accept(&sa, &socklen);
    shared_ptr<NioSocket> rw (new NioSocket(fd));
    cout<<"set io fd non-block result: " << rw->setNonBlock()<<endl;

    int ret;
    string buf;
    // nonblocking but always asking way
    while(-1 == (ret = rw->read(buf, pageSize))){
        if(errno == EAGAIN)
            continue;
        else{
            // throw exception
            break;
        }
    }

    cout<<"read data from socket: size: "<<ret<<", data : "<<buf<<endl;
    string response = "response the message :fuck you ";
    rw->write(response, response.size());
    cout<<"talk done ~"<<endl;
}

void select(shared_ptr<NServerSocket> ns){
    struct sockaddr sa;
    socklen_t socklen;
    int fd = ns->accept(&sa, &socklen);
    shared_ptr<NioSocket> rw (new NioSocket(fd));

}

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

    select(ns);
    //keepQuery(ns);
    //FD_ZERO();
}
