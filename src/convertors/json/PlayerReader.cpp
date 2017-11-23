#include <convertors/json/PlayerReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int PlayerReader::readPlayer(const char * buffer, const int bufferSize, models::PlayerModel * playerModel) const{
        string str;
        str.assign(buffer, bufferSize);
        auto j = nlohmann::json::parse(str);

        try{
            playerModel->setIdx(j["idx"]);
            playerModel->setHome(j["home"]["post_id"]);
            playerModel->setName(j["name"]);

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
