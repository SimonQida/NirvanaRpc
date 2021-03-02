#include "socketBase.h"
namespace nirvana{
    namespace socket{

        class NServerSocket{
            public:
                NServerSocket();
                NServerSocket(int, int, int);
                ~NServerSocket();
                int bind();
                int listen(int);
                int accept(struct sockaddr*, socklen_t*);

            protected:
                int socketFd;
                struct sockaddr_in addr;
        };

        int NServerSocket::bind(){
            int option = 1;
            setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
            return 0 == ::bind(socketFd, (struct sockaddr *)&addr, sizeof(addr));
        }

        int NServerSocket::listen(int times){
            return 0 == ::listen(socketFd, times);
        }

        int NServerSocket::accept(struct sockaddr * addr, socklen_t * len){
            return ::accept(socketFd, addr, len);
        }
    }
}
