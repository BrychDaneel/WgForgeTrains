#include <convertors/json/DynamicMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{

    const int DynamicMapReader::readDynamicMap(const char * buffer, const int bufferSize, models::DynamicMap * dynamicMap) const{
        string str;
        str.assign(buffer, bufferSize);
        auto j = nlohmann::json::parse(str);

        try{
            dynamicMap->setIdx(j["idx"]);

            for (auto jtrain : j["train"]){
                models::TrainModel train;

                train.setIdx(jtrain["idx"]);
                train.setLineIdx(jtrain["line_idx"]);
                train.setPlayerIdx(jtrain["player_id"]);
                train.setPosition(jtrain["position"]);
                train.setSpeed(jtrain["speed"]);

                dynamicMap->addTrain(train);
            }

            for (auto jpost: j["post"]){
                models::PostModel post;

                post.setIdx(jpost["idx"]);
                post.setType(jpost["type"]);
                post.setArmor(jpost["armor"]);
                post.setName(jpost["name"]);
                post.setPopulation(jpost["population"]);
                post.setProduct(jpost["product"]);

                dynamicMap->addPost(post);
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
