#ifndef _I_BOT_SEGMENT_H_
#define _I_BOT_SEGMENT_H_

#include <CommandSender.h>
#include <world/World.h>


namespace tiger
{
namespace trains
{
namespace ai
{

    class IBotSegment
    {
        public:
            virtual ~IBotSegment(){}
            virtual void step() = 0;


    };

}
}
}


#endif
