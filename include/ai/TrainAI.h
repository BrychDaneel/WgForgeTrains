#pragma once


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

            void makeMove();
            int calculateProducts(int tick, world::IPost *post);
            bool needHome();
            void calculatePath(const world::World &world);
            void makeOwnBusyLines(const world::World &world);
            void makePath(const world::World &world);
            std::vector<const world::Point *> getMinPath(const world::Point *point);

            models::PostType getPostTypeByGood(models::GoodType type);
            void changeCurrentBusy();


            std::set<std::pair<int, const world::Line *>> *busyLines;
            std::set<const world::Line *> ownBusy;
            models::GoodType type;
            world::Train *train;
            const world::Point *lastPoint;
            const world::Point *nextPoint;

            std::map<const world::Point*, int> minLen;
            std::map<const world::Point*, const world::Point*> ancestors;
            std::vector<const world::Point *> currentPath;
            std::vector<std::pair<int, const world::Line *>> currentBusy;

            int id;




    };

}
}
}
