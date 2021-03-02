#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <netdb.h>
#include<iostream>
#include<fcntl.h>
#include <unistd.h>
//#include "../log/log.h"
#include "include/socObj.h"
using namespace  std;

void printAddrInfo(struct addrinfo * info){
    struct addrinfo *rp;
    int count = 0;
    for(rp = info; rp != NULL; rp = info->ai_next){
        ++count;
        std::cout<<"addrinfo ip : " << ((struct sockaddr_in*)rp->ai_addr)->sin_addr.s_addr<<std::endl;
    }
    //l.logPrint("addrinfo count : "+ std::to_string(count));
}

int main(){
    //log clientLog("/tmp/client.log", log::ERROR);
    //create socket

    rpcSocket soc;
    struct addrinfo hints, *result;
    //int s = getaddrinfo("127.0.0.2", , NULL, &result);
    //printAddrInfo(result, clientLog);
    
    soc.connect_build("127.0.0.1", 10234);
    if (soc.connectOnce() == false){
        string errStr = strerror(errno);
        //clientLog.errorPrint("connect the server failed : " + errStr);
        return -1;
    }
    string req = "req";
    cout<<"prepare to send String"<<endl;
    soc.sendString(req);
    int readSize = soc.readString(req);
    std::cout<<"read data size: "<<readSize<<std::endl;
    std::cout<<"read data : "<<req<<std::endl;
}
