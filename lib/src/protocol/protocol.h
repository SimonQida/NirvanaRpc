#pragma once
#include "transport/transport.h"

using std::string;
using std::shared_ptr;

namespace nirvana{
    namespace protocol{
        class NProtocolException : public std::exception{
            public:
                NProtocolException();
                NProtocolException(string err);
                const char* what()const noexcept;
            private:
                string errmsg;
        };

        class Nprotocol{
            public:
                Nprotocol(shared_ptr<nirvana::transport::Ntransport>);

                virtual ssize_t readMessageBegin(string& buf) = 0;
                virtual ssize_t readMessageEnd() = 0;

                virtual ssize_t readFieldBegin(const string& buf) = 0;
                virtual ssize_t readFieldEnd() = 0;
                virtual ssize_t readString(string& buf) = 0;
                virtual ssize_t readInt(int&) = 0;

                virtual ssize_t writeMessageBegin(const string& buf) = 0;
                virtual ssize_t writeMessageEnd() = 0;

                virtual ssize_t writeFieldBegin(const string& buf) = 0;
                virtual ssize_t writeFieldEnd() = 0;
                virtual ssize_t writeString(const string& buf) = 0;
                virtual ssize_t writeInt(const int&) = 0;

            protected:
                shared_ptr<nirvana::transport::Ntransport> tran_;
                logging::log* protoLog;
        };
    }
}
