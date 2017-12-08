#include <gtest/gtest.h>
#include <convertors/json/CoordsMapReader.h>
#include <string>
#include <nlohmann/json.hpp>
#include <models/CoordsMap.h>


using namespace testing;

using std::string;
using tiger::trains::models::CoordsMap;


class CoordsMapReaderTests : public ::testing::Test{

protected:

    void SetUp(){

        char * buffer;
        int size = readFile("tests/res/correct_coords.json", &buffer);

        res = coordsMapReader.readCoordsMap(buffer, size, &coordsMap);

        free(buffer);
    }

    void TearDown(){
    }

    tiger::trains::convertors::json::CoordsMapReader coordsMapReader;
    CoordsMap coordsMap;
    int res;

};


TEST_F(CoordsMapReaderTests, baseInfo){
    ASSERT_FALSE(res) << coordsMapReader.getLastErrorMessage();
    ASSERT_EQ(12u, coordsMap.coords.size());
}


TEST_F(CoordsMapReaderTests, size){
    ASSERT_FALSE(res) << coordsMapReader.getLastErrorMessage();

    ASSERT_EQ(200, coordsMap.width);
    ASSERT_EQ(200, coordsMap.height);
}



TEST_F(CoordsMapReaderTests, pointIdx){
    ASSERT_FALSE(res) << coordsMapReader.getLastErrorMessage();

    for (size_t i=0; i<coordsMap.coords.size(); i++)
        ASSERT_EQ((int)i * 4 + 4, coordsMap.coords[i].idx);
}


TEST_F(CoordsMapReaderTests, somePoints){
    ASSERT_FALSE(res) << coordsMapReader.getLastErrorMessage();

    ASSERT_EQ(2, coordsMap.coords[3].x);
    ASSERT_EQ(5, coordsMap.coords[3].y);

    ASSERT_EQ(1, coordsMap.coords[5].x);
    ASSERT_EQ(30, coordsMap.coords[5].y);

    ASSERT_EQ(65, coordsMap.coords[8].x);
    ASSERT_EQ(43, coordsMap.coords[8].y);
}
