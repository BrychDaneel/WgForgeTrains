#include <gtest/gtest.h>
#include <convertors/json/DynamicMapReader.h>
#include <string>
#include <fstream>
#include <tests/reader.h>


using namespace testing;


using tiger::trains::models::PostType;


class DynamicMapReaderTests : public ::testing::Test{

protected:

    void SetUp(){
        tiger::trains::convertors::json::DynamicMapReader dynamicMapReader;

        char * buffer;
        int size = readFile("tests/res/correct_dynamic.json", &buffer);

        res = dynamicMapReader.readDynamicMap(buffer, size, &dynamicMap);
    }

    void TearDown(){
    }

    tiger::trains::models::DynamicMap dynamicMap;
    int res;

};


TEST_F(DynamicMapReaderTests, length){
    ASSERT_FALSE(res);
    ASSERT_EQ(1, dynamicMap.getIdx());
    ASSERT_EQ(4u, dynamicMap.getPostList().size());
    ASSERT_EQ(2u, dynamicMap.getTrainList().size());
}


TEST_F(DynamicMapReaderTests, town){
    ASSERT_FALSE(res);
    tiger::trains::models::PostModel post;
    post = dynamicMap.getPostList()[0];
    ASSERT_EQ(PostType::TOWN, post.getType());
    ASSERT_EQ(2, post.getIdx());
    ASSERT_EQ("town-one", post.getName());
    ASSERT_EQ(0, post.getArmor());
    ASSERT_EQ(3, post.getPopulation());
    ASSERT_EQ(35, post.getProduct());
}


TEST_F(DynamicMapReaderTests, market){
    ASSERT_FALSE(res);
    tiger::trains::models::PostModel post;
    post = dynamicMap.getPostList()[2];
    ASSERT_EQ(PostType::MARKET, post.getType());
    ASSERT_EQ(8, post.getIdx());
    ASSERT_EQ("market-medium", post.getName());
    ASSERT_EQ(28, post.getProduct());
    ASSERT_EQ(28, post.getProductCapacity());
    ASSERT_EQ(1, post.getReplenishment());
}


TEST_F(DynamicMapReaderTests, checkPostsIdx){
    ASSERT_FALSE(res);
    ASSERT_EQ(2, dynamicMap.getPostList()[0].getIdx());
    ASSERT_EQ(4, dynamicMap.getPostList()[1].getIdx());
    ASSERT_EQ(8, dynamicMap.getPostList()[2].getIdx());
    ASSERT_EQ(16, dynamicMap.getPostList()[3].getIdx());
}


TEST_F(DynamicMapReaderTests, train){
    ASSERT_FALSE(res);
    tiger::trains::models::TrainModel train;
    train = dynamicMap.getTrainList()[1];
    ASSERT_EQ(200, train.getCapacity());
    ASSERT_EQ(42, train.getIdx());
    ASSERT_EQ(1, train.getLineIdx());
    ASSERT_EQ("c8e35156-de2f-4690-be43-cccbc116e513", train.getPlayerIdx());
    ASSERT_EQ(3, train.getPosition());
    ASSERT_EQ(5, train.getProduct());
    ASSERT_EQ(tiger::trains::models::SpeedType::REVERSE, train.getSpeed());
}


TEST_F(DynamicMapReaderTests, checkTrainsIdx){
    ASSERT_FALSE(res);
    ASSERT_EQ(33, dynamicMap.getTrainList()[0].getIdx());
    ASSERT_EQ(42, dynamicMap.getTrainList()[1].getIdx());
}
