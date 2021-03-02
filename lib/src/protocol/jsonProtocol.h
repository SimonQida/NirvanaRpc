#pragma once
#include <nlohmann/json.hpp>
#include "protocol.h"

using nirvana::protocol::Nprotocol;
using nlohmann::json;

namespace nirvana{
    namespace protocol{
        class jsonProtocol: public Nprotocol{
            public:
                jsonProtocol(shared_ptr<nirvana::transport::Ntransport> transFd);

                // "rpcMethod": "add_int_int",
                ssize_t readMessageBegin(string& buf);
                ssize_t readMessageEnd();

                ssize_t readFieldBegin(const string& buf);
                ssize_t readFieldEnd();
                ssize_t readString(string& buf);
                ssize_t readInt(int&);

                ssize_t writeMessageBegin(const string& buf);
                ssize_t writeMessageEnd();

                ssize_t writeFieldBegin(const string& buf);
                ssize_t writeFieldEnd();
                ssize_t writeString(const string& buf);
                ssize_t writeInt(const int&);
                ssize_t writeFlush();

            private:
                json readJson, writeJson;
                string writeFieldName;
                string readFieldName;
                ssize_t readFlush();
                void checkFieldNameExit() const;
                
        };
    }
}
