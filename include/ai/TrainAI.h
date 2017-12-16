#ifndef _I_TRAIN_AI_H_
#define _I_TRAIN_AI_H_

#include <CommandSender.h>
#include <ai/IBotSegment.h>
#include <vector>
#include <set>
#include <world/Player.h>
#include <world/Train.h>
#include <models/GoodType.h>
#include <models/PostType.h>


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
            void step();

        private:

            int calculateProducts();
            bool needHome();
            void calculatePath(const world::World &world);
            void makeOwnBusyLines(const world::World &world);
            void makePath(const world::World &world);
            models::PostType getPostTypeByGood(models::GoodType type);

            std::set<std::pair<int, const world::Line *>> *busyLines;
            std::set<const world::Line *> ownBusy;
            models::GoodType type;
            world::Train *train;
            world::Point *lastPoint;
            world::Point *nextPoint;

            std::map<const world::Point*, int> minLen;
            std::map<const world::Point*, const world::Point*> ancestors;
            std::vector<const world::Point *> currentPath;
            int id;




    };

}
}
}


#endif
