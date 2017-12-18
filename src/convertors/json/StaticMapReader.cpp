#include <convertors/json/StaticMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


/*
 * Errors:
 * -1 unknown error
 * 1 - bad buffer
 * 2 - bad json
 * 3 - value error
 */
int StaticMapReader::readStaticMap(const char *buffer, const int bufferSize, models::StaticMap *staticMap)
{
    string str;

    try
    {
        str.assign(buffer, bufferSize);
    }
    catch (...)
    {
        lastErrorCode = 1;
        lastErrorMessage = "Can't conver buffer to string";
        return lastErrorCode;
    }

    nlohmann::json j;

    try
    {
        j = nlohmann::json::parse(str);
    }
    catch (const nlohmann::json::parse_error &e)
    {
        lastErrorCode = 2;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }


    staticMap->clearLineList();
    staticMap->clearPointList();

    try
    {
        staticMap->setIdx(j["idx"]);
        staticMap->setName(j["name"]);

        for (auto jpoint : j["point"])
        {
            models::PointModel point;

            point.setIdx(jpoint["idx"]);

            if (jpoint["post_id"].is_number_integer())
                point.setPostId(jpoint["post_id"]);

            staticMap->addPoint(point);
        }

        for (auto jline: j["line"])
        {
            models::LineModel line;

            line.setIdx(jline["idx"]);
            line.setLength(jline["length"]);
            line.setStartPoint(jline["point"][0]);
            line.setEndPoint(jline["point"][1]);

            staticMap->addLine(line);
        }

    }
    catch(const nlohmann::json::type_error &e)
    {
        lastErrorCode = 3;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }
    catch(...)
    {
        lastErrorCode = -1;
        lastErrorMessage = "Unknown parse data error.";
        return lastErrorCode;
    }

    return 0;
}


int StaticMapReader::getLastErrorCode()
{
    return lastErrorCode;
}


const std::string &StaticMapReader::getLastErrorMessage()
{
    return lastErrorMessage;
}


}
}
}
}
