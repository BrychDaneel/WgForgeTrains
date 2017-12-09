#ifndef TCPSESSION_H
#define TCPSESSION_H

#include <string>
#include "network/TCPClient.h"
#include "network/ResposeMessage.h"
#include <cstring>

namespace tiger
{
    namespace trains
    {
        namespace network
        {
            class TCPSession
            {
                public:

                    TCPSession(const char *name,const char *servAddr, int port);
                    virtual ~TCPSession();
                    ResposeMessage* login();
                    void logout();
                    bool send(const uint8_t* buffer, size_t bufferSize);
                    ResposeMessage* recv();

                private:
                    const char *name;
                    const char *servAddr;
                    int port;
                    TCPClient tcpClient;


            };

        }
    }
}


#endif // TCPSESSION_H
