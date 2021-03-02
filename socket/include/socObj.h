#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>

using std::string;
class rpcSocket{
    public:
        rpcSocket(int domain, int type,int protocol){
            socketFd = socket(domain, type, protocol);
            setDefaultAddr();
        }

        rpcSocket(){
            socketFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            setDefaultAddr();
        }

        ~rpcSocket(){
            close(socketFd);
        }

        void build(string ip, int port){
            setDefaultAddr();
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            addr.sin_port = htons(port);
        }

        void connect_build(string ip, int port, int domain = AF_INET){
            target_addr.sin_family = domain;
            target_addr.sin_addr.s_addr = inet_addr(ip.c_str());
            target_addr.sin_port = htons(port);
        }

        bool connectOnce(){
            return 0 == connect(socketFd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        }

        //todo : realize retry-connect
        bool connectTimes(){
            
            return true;
        }

        bool bind(){
            int option = 1;
            setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
            return 0 == ::bind(socketFd, (struct sockaddr *)&addr, sizeof(addr));
        }

        bool listen(int times){
            return 0 == ::listen(socketFd, times);
        }

        int accept(struct sockaddr * addr, socklen_t * len){
            return ::accept(socketFd, addr, len);
        }

        int sendString(string data){
            return send(socketFd, data.c_str(), data.size(), 0);
        }

        int readString(string& data){
            char buf[100];
            int size = recv(socketFd, buf, 100, 0);
            buf[size] = '\0';
            data = buf;
            return size;
        }

        int getFd() const{
            return socketFd;
        }

    private:
        int socketFd;
        struct sockaddr_in addr;
        struct sockaddr_in target_addr;

        void setDefaultAddr(){
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = inet_addr("127.0.0.1");
            addr.sin_port = htons(10234);
        }

};
