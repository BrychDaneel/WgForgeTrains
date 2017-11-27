#ifndef RESPONSEMESSAGE_H
#define RESPONSEMESSAGE_H
namespace tiger
{
    namespace trains
    {
        namespace network
        {

            struct ResposeMessage
            {
                uint32_t result;
                size_t dataLength;
                char *data;
                ~ResposeMessage()
                {
                    delete data;
                }
            };




        }
    }
}

#endif
