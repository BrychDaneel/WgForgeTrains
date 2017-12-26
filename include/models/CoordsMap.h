#pragma once


#include <vector>
#include <models/CoordModel.h>


namespace tiger
{
namespace trains
{
namespace models
{


struct CoordsMap
{
    CoordsMap() {}
    CoordsMap(const int width, const int height, const std::vector<CoordModel> &coords) :
        width(width), height(height), coords(coords) {}

    int width, height;
    std::vector<CoordModel> coords;

};


}
}
}

