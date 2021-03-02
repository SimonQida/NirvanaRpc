#pragma once
#include<sys/types.h>
#include<string>

namespace nirvana{
    namespace Nio{
        class NioBase{
            public:
                NioBase();
                ~NioBase();
                virtual ssize_t write(const std::string&, int ) = 0;
                virtual ssize_t read(std::string&, int ) = 0;
                virtual ssize_t write(const char*, int ) = 0;
                virtual ssize_t read(char*, int ) = 0;
            protected:
            private:
        };
    }
}
