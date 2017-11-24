#include <convertors/json/MoveWriter.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int MoveWriter::writeMove(const models::MoveModel * move, char * buffer, int * bufferSize) const{
        nlohmann::json j;
        j["line_idx"] = move->getLineIdx();
        j["speed"] = move->getSpeedType();
        j["train_idx"] = move->getTrainIdx();

        std::string str = j.dump();
        const char * cstr = str.c_str();
        int len = strlen(cstr);
        if (len > *bufferSize)
            return -1;

        *bufferSize = len;
        for (int i=0; i<len; i++)
            buffer[i] = cstr[i];

        return 0;
    }

}
}
}
}
