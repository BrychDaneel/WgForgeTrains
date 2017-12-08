#pragma once


#include <models/CoordModel.h>
#include <vector>
#include <string>


namespace tiger{
namespace trains{
namespace convertors{


struct ICoordsMapReader{

    virtual ~ICoordsMapReader(){}

    virtual int readCoordsMap(const char* buffer, const int bufferSize,
                              std::vector<models::CoordModel>& coordsMap) = 0;

    virtual int getLastErrorCode() = 0;
    virtual const std::string& getLastErrorMessage() = 0;
};


}
}
}
