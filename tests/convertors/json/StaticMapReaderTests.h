#include <gtest/gtest.h>
#include <convertors/json/StaticMapReader.h>
#include <string>
#include <fstream>


using namespace testing;


class StaticMapReaderTests : public ::testing::Test{

protected:

    void SetUp(){
        tiger::trains::convertors::json::StaticMapReader staticMapReader;

        char * buffer;
        int size = readFile("tests/res/correct_static.json", &buffer);

        res = staticMapReader.readStaticMap(buffer, size, &staticMap);
    }

    void TearDown(){
    }

    tiger::trains::models::StaticMap staticMap;
    int res;

};


TEST_F(StaticMapReaderTests, baseInfo){
    ASSERT_FALSE(res);
    ASSERT_EQ(1, staticMap.getIdx());
    ASSERT_EQ("map02", staticMap.getName());
    ASSERT_EQ(18u, staticMap.getLineList().size());
    ASSERT_EQ(12u, staticMap.getPointList().size());
}


TEST_F(StaticMapReaderTests, lineIdx){
    for (size_t i=0; i<staticMap.getLineList().size(); i++)
        ASSERT_EQ((int)i * 3 + 3, staticMap.getLineList()[i].getIdx());
}


TEST_F(StaticMapReaderTests, pointIdx){
    for (size_t i=0; i<staticMap.getPointList().size(); i++)
        ASSERT_EQ((int)i * 4 + 4, staticMap.getPointList()[i].getIdx());
}


TEST_F(StaticMapReaderTests, someLines){
    tiger::trains::models::LineModel line3, line7, line10;

    line3 = staticMap.getLineList()[3];
    ASSERT_EQ(1, line3.getLength());
    ASSERT_EQ(10, line3.getStartPoint());
    ASSERT_EQ(4, line3.getEndPoint());

    line7 = staticMap.getLineList()[7];
    ASSERT_EQ(2, line7.getLength());
    ASSERT_EQ(8, line7.getStartPoint());
    ASSERT_EQ(9, line7.getEndPoint());

    line10 = staticMap.getLineList()[10];
    ASSERT_EQ(3, line10.getLength());
    ASSERT_EQ(11, line10.getStartPoint());
    ASSERT_EQ(12, line10.getEndPoint());
}


TEST_F(StaticMapReaderTests, posts){
    int posts[] = {1, 0, 0, 2, 3, 0, 4, 0, 0, 0, 0, 0};

    for (size_t i=0; i<staticMap.getPointList().size(); i++)
        if (posts[i] == 0)
            ASSERT_FALSE(staticMap.getPointList()[i].hasPost());
        else{
            ASSERT_TRUE(staticMap.getPointList()[i].hasPost());
            ASSERT_EQ(posts[i], staticMap.getPointList()[i].getPostId());
        }
}
