#ifndef _JUST_DO_IT_BOT_H_
#define _JUST_DO_IT_BOT_H_

#include <CommandSender.h>
#include <world/World.h>
#include <ai/IBot.h>
#include <ai/Post.h>

namespace tiger
{
    namespace trains
    {
        namespace ai
        {

            class JustDoItBot: public IBot
            {
                public:
                    JustDoItBot();
                    void init(world::World *world);
                    void step();

                private:
                    world::World *world;
                    int tick;


            };

        }
    }
}


#endif
