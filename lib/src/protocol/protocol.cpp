#include "protocol.h"

using namespace nirvana::protocol;
using namespace logging;
using namespace nirvana::transport;

using namespace std;

Nprotocol::Nprotocol(shared_ptr<Ntransport> trans_fd):tran_(trans_fd){
    protoLog = log::getLogger();
}

NProtocolException::NProtocolException(){}
NProtocolException::NProtocolException(string err): errmsg(err){}

const char* NProtocolException::what()const noexcept{
    return errmsg.c_str();
}

