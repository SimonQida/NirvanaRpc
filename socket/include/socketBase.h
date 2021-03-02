#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using std::string;

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

        class NioSocket{
            public:
                NioSocket(int ,int ,int );
                NioSocket();
                NioSocket(int);
                ~NioSocket();
                ssize_t write(const string &, int len);
                ssize_t read(string&, int len);
                void shutdown(shutType flag){
                    ::shutdown(socketFd, flag);
                }

            protected:
                int socketFd;
                //struct sockaddr_in serv_addr;
        };

        const int DefaultPort = 19971;
        class NConnectSocket : NioSocket{
            public:
                NConnectSocket(int, int, int);
                NConnectSocket(int, string, int port = DefaultPort);
                //NConnectSocket();

                ~NConnectSocket();
                void buildTarget(string, int port = DefaultPort);
                int connect();
            private:
                void buildDstAddr(string, int);
                void destory();
                struct sockaddr_in dstAddr;
                
        };
    }
}
