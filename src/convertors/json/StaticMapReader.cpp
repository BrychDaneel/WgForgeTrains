#include <convertors/json/StaticMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int StaticMapReader::readStaticMap(const char * buffer, const int bufferSize, models::StaticMap * staticMap) const{

        string str;
        str.assign(buffer, bufferSize);
        auto j = nlohmann::json::parse(str);

        staticMap->clearLineList();
        staticMap->clearPointList();

        try{
            staticMap->setIdx(j["idx"]);
            staticMap->setName(j["name"]);

            for (auto jpoint : j["point"]){
                models::PointModel point;

                point.setIdx(jpoint["idx"]);
                if (jpoint["post_id"].is_number_integer())
                    point.setPostId(jpoint["post_id"]);

                staticMap->addPoint(point);
            }

            for (auto jline: j["line"]){
                models::LineModel line;

                line.setIdx(jline["idx"]);
                line.setLength(jline["length"]);
                line.setStartPoint(jline["point"][0]);
                line.setEndPoint(jline["point"][1]);

                staticMap->addLine(line);
            }

        }
        catch(const std::domain_error& e){
            return - 1;
        }
        catch(const std::out_of_range& e){
            return - 1;
        }

        return 0;
    }

}
}
}
}
