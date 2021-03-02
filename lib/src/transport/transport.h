#pragma once
#include "socketBase.h"
#include "logging.h"
#include<memory>
#include<fmt/core.h>

namespace nirvana{
    namespace transport{
        class Ntransport{
            public:
                Ntransport(std::shared_ptr<Nio::NioBase>);
                virtual ~Ntransport();
                virtual int write(const std::string&) = 0;
                virtual int write(const char* ,int) = 0;
                virtual int read(std::string&, int) = 0;
                virtual int read(char*, int) = 0;
                virtual void reset() = 0;
                virtual int isClear()const = 0;
                virtual void writeFlush() = 0;
            protected:
                std::shared_ptr<Nio::NioBase> transportFd;
        };
    }
}
