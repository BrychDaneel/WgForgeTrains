#ifndef _I_TRAIN_AI_H_
#define _I_TRAIN_AI_H_

#include <CommandSender.h>
#include <ai/IBotSegment.h>
#include <vector>
#include <set>
#include <world/Player.h>
#include <world/Train.h>
#include <models/GoodType.h>


namespace tiger
{
namespace trains
{
namespace ai
{

    class TrainAI: public IBotSegment
    {
        public:
            TrainAI(std::set<std::pair<int ,const world::Line *>> *busyLines,
                    models::GoodType type, world::Train *train);
            void step(const world::World &world);

        private:

            int calculateProducts();
            bool needHome();
            void calculatePath();
            void makeOwnBusyLines(const world::World &world);
            void makePath();

            std::set<std::pair<int, const world::Line *>> *busyLines;
            std::set<const world::Line *> ownBusy;
            models::GoodType type;
            world::Train *train;


            std::vector<const world::Point *> currentPath;
            int id;




    };

}
}
}


#endif
