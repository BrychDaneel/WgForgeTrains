#pragma once


namespace tiger{
namespace trains{
namespace models{


struct CoordModel
{
    CoordModel(){}
    CoordModel(const int x, const int y, const int idx) : x(x), y(y), idx(idx){}
    int x, y, idx;
};


}
}
}
