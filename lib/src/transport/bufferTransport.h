#pragma once
#include "logging.h"
#include "transport.h"

namespace nirvana{
    namespace transport{
        const int bufSize = 1024;

        class NBufTException :public std::exception{
            public:
                NBufTException();
                NBufTException(std::string err);
                const char* what()const noexcept;
            private:
                std::string errmsg;
        }; 

        class NBuffertransport: public Ntransport{
            public:
                NBuffertransport(std::shared_ptr<Nio::NioBase>, const std::string& logHeader = "default-line");
                ~NBuffertransport();
                int writeSlow(const char* data, int size);
                int readSlow(std::string &data, int size);

                int write(const char* ,int);
                int write(const std::string& data);
                int read(std::string& data, int len);
                // you shall do fix this string
                int read(char*, int);
                //writeInt
                //readInt

                void writeFlush();
                bool readFlush();
                void reset();
                int isClear()const;

            private:
                logging::log* bufferLog;
                std::string logName;
                void reportCursor(const logging::logLevel& ll = logging::DEBUG)const;
                void rebuf();
                int bufMap(int origin);
                std::string readFromRbuf(int size);
                void writeToRbuf(const std::string& stream);
                char readBuf[bufSize];
                char writeBuf[bufSize];

                void logPrint(const std::string&, const logging::logLevel& x=logging::INFO)const;
                //for write: begin always being 0, wCur stand next empty place
                int wCur;
                bool streamDry;
                int rBegin, rEnd;
        };
    }
}
