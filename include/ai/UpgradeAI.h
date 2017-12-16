#ifndef _I_UPGRADE_AI_H_
#define _I_UPGRADE_AI_H_

#include <CommandSender.h>
#include <ai/IBotSegment.h>
#include <world/World.h>


namespace tiger
{
namespace trains
{
namespace ai
{

    class TrainAI: public IBotSegment
    {
        public:
            void step(const world::World &world);


    };

}
}
}


#endif
