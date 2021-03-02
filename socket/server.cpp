#include<iostream>
#include<sys/select.h>
#include<sys/time.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<fcntl.h>
#include <unistd.h>
//#include "../log/log.h"
#include "include/socObj.h"

using namespace std;

string calc(string revBuf){
    //log serverLog("/tmp/server.log", log::LOG);
    //serverLog.print("receive data : " + revBuf +"\trevBuf.size : " + std::to_string(revBuf.size()));
    string res = std::to_string(revBuf.size());
    //serverLog.print("calc data result : " + res);
    return res;
}

int main(){
    //log serverLog("/tmp/server.log", log::ERROR);
    //create socket
    rpcSocket serSoc;

    //serverLog.logPrint("init socket success");
    //touch sockaddr_in stru
    if(serSoc.bind() == false){
        //serverLog.errorPrint("bind failed : " + string(strerror(errno)));
        return -1;
    }

    if(serSoc.listen(10) == false){
        //serverLog.errorPrint("listen failed : " + string(strerror(errno)));
        return -1;
    }

    //serverLog.logPrint("listen port success, ready to accept require");
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen;
    int count = 0;
    cout<<"ready to receive client link"<<endl;
    int acceptFd = serSoc.getFd();
    int maxFd = 1;
    fd_set input;
    FD_ZERO(&input);
    FD_SET(acceptFd, &input);
    maxFd = max(maxFd, acceptFd);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int data_sock = serSoc.accept((struct sockaddr*)&clientAddr, &clientAddrLen);
    fcntl(data_sock, F_SETFL, O_NONBLOCK);
    FD_SET(data_sock, &input);
    FD_SET(1, &input);
    maxFd = max(maxFd, data_sock);
    cout<<FD_ISSET(acceptFd, &input);
    cout<<FD_ISSET(data_sock, &input);

    char buf[256];
    while(1){
        FD_SET(data_sock, &input);
        FD_SET(1, &input);
        int retVal = select(maxFd, &input, NULL, NULL, &timeout);
        cout<<"loop stamp , retVal : "<<retVal<<endl;
        if(retVal == -1){
            cerr<<"error accur in select process and errmsg: "<< strerror(errno)<<endl;
        }
        else{
            if(FD_ISSET(1, &input)){
                read(1, buf, 255);
            }
            else if(FD_ISSET(data_sock, &input)){
                read(data_sock, buf, 255);
            }
            cout<<"get data :"<< buf<<endl;
            //cout<<"test acceptFd result: "<<FD_ISSET(data_sock, &input);
        }
    }

    //FD_SET(xx, &input);
    //FD_CLR(xx, &input);
    while(count < 3){
        int data_sock = serSoc.accept((struct sockaddr*)&clientAddr, &clientAddrLen);
        //int data_sock = serSoc.accept(NULL, NULL);
        if(data_sock < 0){
            //serverLog.errorPrint("error in accepting ");
            return -1;
        }
        //serverLog.logPrint("ESTABLISHED connection");
        //serverLog.logPrint(string("client ip : ") + inet_ntoa(clientAddr.sin_addr) + "\tclient port : " + std::to_string(clientAddr.sin_port));
        char revBuf[100] = {0};
        std::cout<<"data receive size : "<<recv(data_sock, revBuf, 100, 0)<<std::endl;
        string data = calc(revBuf);
        std::cout<<"data send size : "<<send(data_sock,data.c_str(),data.size(), 0)<<std::endl;
        close(data_sock);
        ++ count;
    }
}

