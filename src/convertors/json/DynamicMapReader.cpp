#include <convertors/json/DynamicMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger{
namespace trains{
namespace convertors{
namespace json{


int DynamicMapReader::readDynamicMap(const char* buffer, const int bufferSize, models::DynamicMap* dynamicMap) const
{
    string str;
    str.assign(buffer, bufferSize);
    auto j = nlohmann::json::parse(str);

    dynamicMap->clearPostList();
    dynamicMap->clearTrainList();

    try{
        dynamicMap->setIdx(j["idx"]);

        for (auto jtrain : j["train"]){
            models::TrainModel train;

            train.setIdx(jtrain["idx"]);

            if (jtrain["line_idx"].is_number_integer())
                train.setLineIdx(jtrain["line_idx"]);

            train.setPlayerIdx(jtrain["player_id"]);

            if (jtrain["position"].is_number_integer())
                train.setPosition(jtrain["position"]);

            train.setSpeed(jtrain["speed"]);
            train.setCapacity(jtrain["capacity"]);
            train.setProduct(jtrain["product"]);

            dynamicMap->addTrain(train);
        }

        for (auto jpost: j["post"]){
            models::PostModel post;

            post.setIdx(jpost["idx"]);

            post.setType(jpost["type"]);

            if (jpost["armor"].is_number_integer())
                post.setArmor(jpost["armor"]);

            post.setName(jpost["name"]);

            if (jpost["population"].is_number_integer())
                post.setPopulation(jpost["population"]);

            post.setProduct(jpost["product"]);

            if (jpost["replenishment"].is_number_integer())
                post.setReplenishment(jpost["replenishment"]);

            if (jpost["product_capacity"].is_number_integer())
                post.setProductCapacity(jpost["product_capacity"]);

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
