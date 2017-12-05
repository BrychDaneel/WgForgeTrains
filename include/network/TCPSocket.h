#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

namespace tiger
{
    namespace trains
    {
        namespace network
        {
            class TCPSocket {
            public:
                TCPSocket();
                bool init();
                bool bind(uint32_t addr, int port);
                bool bind(int port);
                bool connect(uint32_t addr, int port);
                int send(const uint8_t *buffer, size_t bufferSize);
                int recv(uint8_t *buffer, size_t maxBytes);
                void close();


            private:
                int pSocket;
                struct sockaddr_in  serverSockAddr;
                struct sockaddr_in  clientSockAddr;

                bool isSocketValid() {return pSocket != -1;}


            };


        }

    }
}

#endif
