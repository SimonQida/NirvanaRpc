#pragma once
#include<string>
#include<sys/socket.h>
#include<fcntl.h>
#include<sys/types.h>
#include<netinet/in.h>
#include "NioBase.h"
#include<arpa/inet.h>

namespace nirvana{
    namespace socket{
        enum AFType{
            INET,
            INET6,
            UNIX,
            USPEC
        };

        enum sockType{
            DGAM,
            RAW,
            SEQPACKET,
            STREAM
        };

        enum ipType{
            IP
        };

        enum shutType{
            RD,
            WR,
            RDWR
        };

        typedef int tranSize;
        const int rFlag = 1<<0;
        const int wFlag = 1<<1;

        class NioSocket : public nirvana::Nio::NioBase{
            public:
                NioSocket(int ,int ,int );
                NioSocket();
                NioSocket(int);
                ~NioSocket();
                ssize_t write(const std::string &, int len);
                ssize_t write(const char *, int len);
                ssize_t read(std::string&, int len);
                ssize_t read(char *, int len);
                void shutdown(shutType flag){
                    ::shutdown(socketFd, flag);
                }
                //int fcntlFd(int cmd, ...);
                int setNonBlock();
            protected:
                int socketFd;
                //struct sockaddr_in serv_addr;
        };

        const int DefaultPort = 12345;

        class NConnectSocket : public NioSocket{
            public:
                NConnectSocket(int, int, int);
                NConnectSocket(std::string, int port = DefaultPort);
                NConnectSocket();

                ~NConnectSocket();
                void buildTarget(std::string, int port = DefaultPort);
                int connect();
            private:
                void buildDstAddr(std::string, int);
                void destory();
                struct sockaddr_in dstAddr;
                
        };
    }
}
