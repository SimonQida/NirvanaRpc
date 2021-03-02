#include "csocket.h"
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using std::string;
using nirvana::socket::NServerSocket;

NServerSocket::NServerSocket(){
    socketFd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    setListenMessage("127.0.0.1", defaultListenPort);
}

NServerSocket::NServerSocket(int domain, int type, int protocol){
    socketFd = ::socket(domain, type, protocol);
    setListenMessage("127.0.0.1", defaultListenPort);
}

NServerSocket::NServerSocket(string ip, int port){
    socketFd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    setListenMessage(ip, port);
}

NServerSocket::~NServerSocket(){
    close(socketFd);
}

int NServerSocket::bind(){
    int option = 1;
    setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    return 0 == ::bind(socketFd, (struct sockaddr *)&listenAddr, sizeof(listenAddr));
}

int NServerSocket::listen(int times){
    return 0 == ::listen(socketFd, times);
}

int NServerSocket::accept(struct sockaddr * addr, socklen_t * len){
    return ::accept(socketFd, addr, len);
}

void NServerSocket::setListenMessage(string ip, int port){
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    listenAddr.sin_port = htons(port);
}

