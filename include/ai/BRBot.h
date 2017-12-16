#ifndef _BR_BOT_H_
#define _BR_BOT_H_

#include <CommandSender.h>
#include <world/World.h>
#include <ai/IBot.h>
#include <ai/Post.h>
#include <ai/ArtMarket.h>
#include <ai/ArtTown.h>
#include <ai/IBotSegment.h>
#include <map>
#include <vector>

namespace tiger
{
namespace trains
{
namespace ai
{

    class BRBot: public IBot
    {
        public:
            BRBot();
            void init(world::World *world);
            void step();
            ~BRBot()
            {
                for (auto botSegment : listBotSegment)
                {
                    delete botSegment;
                }
            }

        private:

            world::World *world;
            int tick;
            std::vector<IBotSegment* > listBotSegment;



    };

}
}
}


#endif
