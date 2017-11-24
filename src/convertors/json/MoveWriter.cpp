#include <convertors/json/MoveWriter.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int MoveWriter::writeMove(const models::MoveModel * move, char * buffer, const int bufferSize) const{
        nlohmann::json j;
        j["line_idx"] = move->getLineIdx();
        j["speed"] = move->getSpeedType();
        j["train_idx"] = move->getTrainIdx();

        const char * cstr = j.dump().c_str();
        int len = strlen(cstr);
        if (len > bufferSize)
            return -1;

        for (int i=0; i<len; i++)
            buffer[i] = cstr[i];

        return 0;
    }

}
}
}
}
