#pragma once


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
                char *data = nullptr;

                ~ResposeMessage()
                {
                    delete data;
                }
            };




        }
    }
}
