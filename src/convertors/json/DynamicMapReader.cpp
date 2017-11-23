#include <convertors/json/DynamicMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int DynamicMapReader::readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const{
        //string str = Encoding.UTF8.GetString(buffer, 0, bufferSize);
        //auto j3 = nlohmann::json::parse(str);
    }


}
}
}
}
