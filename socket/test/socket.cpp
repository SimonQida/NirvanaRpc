#include "../include/socketBase.h"

using namespace nirvana::socket;

int main(){
    NConnectSocket ns(AFType::INET, sockType::STREAM, ipType::IP);
}
