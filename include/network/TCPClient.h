#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "network/TCPSocket.h"
#include <netdb.h>

namespace tiger
{
    namespace trains
    {
        namespace network
        {
            class TCPClient
            {
                public:
                    TCPClient();
                    virtual ~TCPClient();

                    bool connect(const char* addr, int port);
                    int send(const uint8_t *buffer, size_t bufferSize);
                    int recv(uint8_t *buffer, size_t maxBytes);


                protected:

                private:
                    TCPSocket tcpSocket;
            };

        }
    }
}
#endif // TCPClient_H
