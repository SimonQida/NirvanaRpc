#include "NioVoid.h"

using nirvana::xVoid::NioVoid;
using std::string;

NioVoid::NioVoid():curChar('a'){ }

NioVoid::~NioVoid(){ }

void NioVoid::charIncrease(){
    if(curChar + 1 > 'z')
        curChar = 'A';
    else if(curChar + 1 > 'Z')
        curChar = 'a';
    else
        ++curChar;
}

ssize_t NioVoid::write(const std::string& data, int len){
    return data.size();
}

ssize_t NioVoid::read(std::string& data, int len){
    if(len <= 0)
        return 0;
    data = string(len - std::to_string(len).size(), curChar) + std::to_string(len);
    charIncrease();
    return len;
}

ssize_t NioVoid::write(const char*buf, int len){
    return len;
}

ssize_t NioVoid::read(char*buf, int len){
    if(len <= 0)
        return 0;
    strncpy(buf, (string(len - std::to_string(len).size(), curChar) + std::to_string(len)).c_str(), len);
    charIncrease();
    return len;
}
