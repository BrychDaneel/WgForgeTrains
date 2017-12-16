#ifndef _COMPLEX_BOT_H_
#define _COMPLEX_BOT_H_

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

    class ComplexBot: public IBot
    {
        public:
            ComplexBot();
            void init(world::World *world);
            void step();
            ~ComplexBot()
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
