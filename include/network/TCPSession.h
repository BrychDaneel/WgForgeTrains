#ifndef TCPSESSION_H
#define TCPSESSION_H

#include "TCPSocket.h"
#include <netdb.h>

namespace tiger
{
    namespace trains
    {
        namespace network
        {
            class TCPSession
            {
                public:
                    TCPSession();
                    virtual ~TCPSession();

                    bool connect(const char* addr, int port);
                    int send(const uint8_t *buffer, int bufferSize);
                    int recv(uint8_t *buffer, int maxBytes);


                protected:

                private:
                    TCPSocket tcpSocket;
            };

        }
    }
}
#endif // TCPSESSION_H
