#include "socketBase.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

using nirvana::socket::NioSocket;
using nirvana::socket::NConnectSocket;
using std::string;

NioSocket::NioSocket(int domain, int type, int protocol){
    socketFd = ::socket(domain, type, protocol);
}

NioSocket::NioSocket(int SFD):socketFd(SFD){}

NioSocket::NioSocket(){
    socketFd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
}

NioSocket::~NioSocket(){
    close(socketFd);
}

ssize_t NioSocket::write(const char* data, int len){
    return ::write(socketFd, data, len);
}

ssize_t NioSocket::read(char* data, int len){
    return ::read(socketFd, data, len);
}

ssize_t NioSocket::write(const string& data, int len){
    return ::write(socketFd, data.c_str(), len);
}

ssize_t NioSocket::read(string& data, int len){
    char* buf = new char[len];
    ssize_t readLen = ::read(socketFd, buf, len);
    if (readLen >= 0){
        buf[readLen] = 0;
        data = string(buf, readLen);
    }

    delete[] buf;
    return readLen;
}


int NioSocket::setNonBlock(){
    return fcntl(socketFd, F_SETFL, O_NONBLOCK);
}

NConnectSocket::NConnectSocket(int domain, int type, int protocol):NioSocket(domain, type, protocol){}
NConnectSocket::NConnectSocket(string ip, int port):NioSocket(){
    buildDstAddr(ip, port);
}

NConnectSocket::NConnectSocket():NioSocket(){}
NConnectSocket::~NConnectSocket(){
}

void NConnectSocket::buildTarget(string ip, int port){
    buildDstAddr(ip, port);
}

//todo retry--connect
int NConnectSocket::connect(){
    return 0 == ::connect(socketFd, (struct sockaddr *)&dstAddr, sizeof(dstAddr));
}

void NConnectSocket::buildDstAddr(string ip, int port){
    dstAddr.sin_family = AF_INET;
    dstAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    dstAddr.sin_port = htons(port);
}

void NConnectSocket::destory(){
    
}
