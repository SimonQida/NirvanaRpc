#include "transport.h"

using namespace nirvana::transport;
using std::shared_ptr;
using namespace nirvana::Nio;

Ntransport::Ntransport(shared_ptr<NioBase> NioPtr):transportFd(NioPtr){}

Ntransport::~Ntransport(){}