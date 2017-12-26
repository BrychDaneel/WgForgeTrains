#include <convertors/json/DynamicMapReader.h>


#include <nlohmann/json.hpp>


namespace tiger
{
namespace trains
{
namespace convertors
{
namespace json
{


void DynamicMapReader::readEvent(const nlohmann::json &jevent, models::EventModel *event)
{
    event->setTick(jevent["tick"]);
    event->setType(jevent["type"]);

    switch (event->getType())
    {
    case models::EventType::HIJACKERS_ASSAULT:
        event->setParametrs(jevent["hijackers_power"]);
        break;

    case models::EventType::PARASITES_ASSAULT:
        event->setParametrs(jevent["parasites_power"]);
        break;

    case models::EventType::REFUGEES_ARRIVAL:
        event->setParametrs(jevent["refugees_number"]);
        break;

    case models::EventType::TRAIN_COLLISION:
        event->setParametrs(jevent["train"]);
        break;

    default:
        break;
    }
}


void DynamicMapReader::readTrain(const nlohmann::json &jtrain, models::TrainModel *train)
{

    train->clearEventList();

    train->setIdx(jtrain["idx"]);
    train->setLineIdx(jtrain["line_idx"]);
    train->setPlayerIdx(jtrain["player_id"]);
    train->setPosition(jtrain["position"]);
    train->setSpeed(jtrain["speed"]);
    train->setGoods(jtrain["goods"]);
    train->setGoodsCapacity(jtrain["goods_capacity"]);

    if (jtrain["post_type"].is_null())
        train->setGoodsType(models::GoodType::NONE);
    else
        train->setGoodsType(jtrain["post_type"]);

    train->setLevel(jtrain["level"]);

    if (jtrain["next_level_price"].is_number())
        train->setNextLevelPrice(jtrain["next_level_price"]);
    else
        train->setNextLevelPrice(-1);

    for (nlohmann::json jevent : jtrain["event"])
    {
        models::EventModel event;
        readEvent(jevent, &event);
        train->addEvent(event);
    }

}


void DynamicMapReader::readTown(const nlohmann::json &jtown, models::PostModel *post)
{

    post->setProduct(jtown["product"]);
    post->setProductCapacity(jtown["product_capacity"]);
    post->setArmor(jtown["armor"]);
    post->setPopulation(jtown["population"]);
    post->setArmorCapacity(jtown["armor_capacity"]);

    if (jtown["next_level_price"].is_number())
        post->setNextLevelPrice(jtown["next_level_price"]);
    else
        post->setNextLevelPrice(-1);

    post->setPopulationCapacity(jtown["population_capacity"]);
    post->setLevel(jtown["level"]);

}


void DynamicMapReader::readMarket(const nlohmann::json &jmarket, models::PostModel *post)
{
    post->setProduct(jmarket["product"]);
    post->setProductCapacity(jmarket["product_capacity"]);
    post->setReplenishment(jmarket["replenishment"]);

}

void DynamicMapReader::readStorage(const nlohmann::json &jstorage, models::PostModel *post)
{
    post->setArmor(jstorage["armor"]);
    post->setArmorCapacity(jstorage["armor_capacity"]);

}


void DynamicMapReader::readPost(const nlohmann::json &jpost, models::PostModel *post)
{

    post->clearEventList();

    post->setIdx(jpost["idx"]);
    post->setType(jpost["type"]);
    post->setName(jpost["name"]);


    for (nlohmann::json jevent : jpost["event"])
    {
        models::EventModel event;
        readEvent(jevent, &event);
        post->addEvent(event);
    }

    switch (post->getType())
    {

    case models::PostType::TOWN:
        readTown(jpost, post);
        break;

    case models::PostType::MARKET:
        readMarket(jpost, post);
        break;

    case models::PostType::STORAGE:
        readStorage(jpost, post);
        break;

    default:
        break;
    }
}


/*
 * Errors:
 * -1 unknown error
 * 1 - bad buffer
 * 2 - bad json
 * 3 - value error
 */
int DynamicMapReader::readDynamicMap(const char *buffer, const int bufferSize, models::DynamicMap *dynamicMap)
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

    nlohmann::json jmap;

    try
    {
        jmap = nlohmann::json::parse(str);
    }
    catch (const nlohmann::json::parse_error &e)
    {
        lastErrorCode = 2;
        lastErrorMessage = e.what();
        return lastErrorCode;
    }

    dynamicMap->clearPostList();
    dynamicMap->clearTrainList();

    try
    {
        dynamicMap->setIdx(jmap["idx"]);

        for (auto jtrain : jmap["train"])
        {
            models::TrainModel train;
            readTrain(jtrain, &train);
            dynamicMap->addTrain(train);
        }

        for (auto jpost: jmap["post"])
        {
            models::PostModel post;
            readPost(jpost, &post);
            dynamicMap->addPost(post);
        }

        for (auto jscore = jmap["rating"].begin(); jscore != jmap["rating"].end(); jscore++)
        {
            dynamicMap->addScore(jscore.key(), jscore.value());
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


int DynamicMapReader::getLastErrorCode()
{
    return lastErrorCode;
}


const std::string &DynamicMapReader::getLastErrorMessage()
{
    return lastErrorMessage;
}


}
}
}
}
