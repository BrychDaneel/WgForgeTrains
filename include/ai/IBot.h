#ifndef _I_BOT_H_
#define _I_BOT_H_

#include <CommandSender.h>
#include <world/World.h>

namespace tiger
{
    namespace trains
    {
        namespace ai
        {

            class IBot
            {
                public:
                    virtual ~IBot(){};
                    virtual void init(world::World *world) = 0;
                    virtual void step() = 0;


            };

        }
    }
}


#endif
