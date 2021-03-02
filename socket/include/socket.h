namespace nirvana{
    namespace socket{
        enum AFType{
            AF_INET,
            AF_INET6,
            AF_UNIX,
            AF_USPEC
        };
        enum sockType{
            SOCK_DGAM,
            SOCK_RAW,
            SOCK_SEQPACKET,
            SOCK_STREAM
        };
        enum ipType{
            IPPROTO_IP

        };
        typedef int tranSize;
        enum shutType{
            SHUT_RD,
            SHUT_WR,
            SHUT_RDWR
        };
        const int rFlag = 1<<0;
        const int wFlag = 1<<1;

        class socketBase{
            public:
                socketBase(int domain, int type, int protocol);
                socketBase();
                ~socketBase();
                void build();
                tranSize write();
                tranSize read();
                void shutdown(shutType flag){
                    shutdown(socketFd, flag);
                }
            private:
                int socketFd;

        };
    }
}
