#pragma once
#include "NioBase.h"

namespace nirvana{
    namespace xVoid{
        class NioVoid : public nirvana::Nio::NioBase{
            public:
                NioVoid();
                ~NioVoid();
                ssize_t write(const std::string&, int );
                ssize_t read(std::string&, int );
                ssize_t write(const char*, int );
                ssize_t read(char*, int );
                void charIncrease();
            private:
                char curChar;
        };
    }
}
