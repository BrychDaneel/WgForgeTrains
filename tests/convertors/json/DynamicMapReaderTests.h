#include <gtest/gtest.h>
#include <convertors/json/DynamicMapReader.h>
#include <string>
#include <fstream>
#include <tests/reader.h>
#include <models/EventModel.h>


using namespace testing;


using tiger::trains::models::PostType;
using tiger::trains::models::EventModel;
using tiger::trains::models::EventType;


class DynamicMapReaderTests : public ::testing::Test{

protected:

    tiger::trains::convertors::json::DynamicMapReader dynamicMapReader;

    void SetUp(){

        char * buffer;
        int size = readFile("tests/res/correct_dynamic.json", &buffer);

        res = dynamicMapReader.readDynamicMap(buffer, size, &dynamicMap);

        free(buffer);
    }

    void TearDown(){
    }

    tiger::trains::models::DynamicMap dynamicMap;
    int res;

};


TEST_F(DynamicMapReaderTests, length){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    ASSERT_EQ(1, dynamicMap.getIdx());
    ASSERT_EQ(6u, dynamicMap.getPostList().size());
    ASSERT_EQ(2u, dynamicMap.getTrainList().size());
}


TEST_F(DynamicMapReaderTests, town){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    tiger::trains::models::PostModel post;
    post = dynamicMap.getPostList()[0];
    ASSERT_EQ(PostType::TOWN, post.getType());
    ASSERT_EQ(2, post.getIdx());
    ASSERT_EQ("town-one", post.getName());
    ASSERT_EQ(100, post.getArmor());
    ASSERT_EQ(3, post.getPopulation());
    ASSERT_EQ(350, post.getProduct());

    ASSERT_EQ(1, post.getLevel());
    ASSERT_EQ(100, post.getNextLevelPrice());
    ASSERT_EQ(10, post.getPopulationCapacity());
    ASSERT_EQ(200, post.getProductCapacity());
    ASSERT_EQ(100, post.getArmorCapacity());
}


TEST_F(DynamicMapReaderTests, someMarket){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    tiger::trains::models::PostModel post;
    post = dynamicMap.getPostList()[2];
    ASSERT_EQ(PostType::MARKET, post.getType());
    ASSERT_EQ(8, post.getIdx());
    ASSERT_EQ("market-medium", post.getName());
    ASSERT_EQ(250, post.getProduct());
    ASSERT_EQ(250, post.getProductCapacity());
    ASSERT_EQ(10, post.getReplenishment());
}


TEST_F(DynamicMapReaderTests, checkPostsIdx){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    ASSERT_EQ(2, dynamicMap.getPostList()[0].getIdx());
    ASSERT_EQ(4, dynamicMap.getPostList()[1].getIdx());
    ASSERT_EQ(8, dynamicMap.getPostList()[2].getIdx());
    ASSERT_EQ(16, dynamicMap.getPostList()[3].getIdx());
}


TEST_F(DynamicMapReaderTests, train){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    tiger::trains::models::TrainModel train;
    train = dynamicMap.getTrainList()[1];
    ASSERT_EQ(40, train.getGoodsCapacity());
    ASSERT_EQ(42, train.getIdx());
    ASSERT_EQ(1, train.getLineIdx());
    ASSERT_EQ("be9d34af-de62-4759-9b77-47be1ad8cefc", train.getPlayerIdx());
    ASSERT_EQ(3, train.getPosition());
    ASSERT_EQ(5, train.getGoods());
    ASSERT_EQ(tiger::trains::models::SpeedType::REVERSE, train.getSpeed());

    ASSERT_EQ(1, train.getLevel());
    ASSERT_EQ(40, train.getNextLevelPrice());
    ASSERT_EQ(tiger::trains::models::GoodType::NONE, train.getGoodsType());
}


TEST_F(DynamicMapReaderTests, checkTrainsIdx){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();
    ASSERT_EQ(33, dynamicMap.getTrainList()[0].getIdx());
    ASSERT_EQ(42, dynamicMap.getTrainList()[1].getIdx());
}


TEST_F(DynamicMapReaderTests, postEvents){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();

    ASSERT_EQ(3u, dynamicMap.getPostList()[0].getEventList().size());

    EventModel event = dynamicMap.getPostList()[0].getEventList()[0];
    ASSERT_EQ(3, event.getParametrs());
    ASSERT_EQ(111, event.getTick());
    ASSERT_EQ(EventType::PARASITES_ASSAULT, event.getType());

    event = dynamicMap.getPostList()[0].getEventList()[1];
    ASSERT_EQ(2, event.getParametrs());
    ASSERT_EQ(1, event.getTick());
    ASSERT_EQ(EventType::HIJACKERS_ASSAULT, event.getType());

    event = dynamicMap.getPostList()[0].getEventList()[2];
    ASSERT_EQ(1, event.getParametrs());
    ASSERT_EQ(1, event.getTick());
    ASSERT_EQ(EventType::REFUGEES_ARRIVAL, event.getType());
}


TEST_F(DynamicMapReaderTests, trainEvents){
    ASSERT_FALSE(res) << dynamicMapReader.getLastErrorMessage();

    ASSERT_EQ(1u, dynamicMap.getTrainList()[0].getEventList().size());

    EventModel event = dynamicMap.getTrainList()[0].getEventList()[0];
    ASSERT_EQ(2, event.getParametrs());
    ASSERT_EQ(2, event.getTick());
    ASSERT_EQ(EventType::TRAIN_COLLISION, event.getType());

}
