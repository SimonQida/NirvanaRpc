#pragma once
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

namespace nirvana{
    namespace socket{

        const int defaultListenPort = 12345;
        class NServerSocket{
            public:
                NServerSocket();
                NServerSocket(std::string, int);
                NServerSocket(int, int, int);
                ~NServerSocket();
                int bind();
                int listen(int);
                int accept(struct sockaddr*, socklen_t*);

            protected:
                void setListenMessage(std::string, int);
                int socketFd;
                struct sockaddr_in listenAddr;
        };
    }
}
