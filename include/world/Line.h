#pragma once
#ifndef _TIGER_TRAINS_WORLD_LINE_H_
#define _TIGER_TRAINS_WORLD_LINE_H_


#include <world/World.h>
#include <models/LineModel.h>

#include <vector>


namespace tiger{
namespace trains{
namespace world{

    class World;
    class Point;

    class Line{

        private:
            World * owner;
            Point * startPont;
            Point * endPont;
            int length;
        public:
            Line();
            Line(const models::LineModel& model, World * world);

            World * getWorld() const;

            Point * getStartPont() const;
            Point * getEndPont() const;

            const std::vector<Point*>& getPoints() const;

            int getLenght() const;

    };
}
}
}



#endif


