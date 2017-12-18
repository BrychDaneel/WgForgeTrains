#include <models/StaticMap.h>
#include <nlohmann/json.hpp>


namespace tiger
{
namespace trains
{
namespace models
{


StaticMap::StaticMap()
{
}


StaticMap::StaticMap(const int idx, const string name)
    : idx(idx), name(name)
{
}


void StaticMap::addPoint(const PointModel &point)
{
    pointList.push_back(point);
}


void StaticMap::addLine(const LineModel &line)
{
    lineList.push_back(line);
}


int StaticMap::getIdx() const
{
    return idx;
}


const string StaticMap::getName() const
{
    return name;
}


const vector<LineModel> &StaticMap::getLineList() const
{
    return lineList;
}


const vector<PointModel> &StaticMap::getPointList() const
{
    return pointList;
}


void StaticMap::setIdx(const int idx)
{
    this->idx = idx;
}


void StaticMap::setName(const string name)
{
    this->name = name;
}


void StaticMap::clearLineList()
{
    lineList.clear();
}


void StaticMap::clearPointList()
{
    pointList.clear();
}


}
}
}
