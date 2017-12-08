#include <gtest/gtest.h>
#include <convertors/json/CoordsMapReader.h>
#include <string>
#include <nlohmann/json.hpp>


using namespace testing;

using std::string;
using tiger::trains::models::CoordModel;


class CoordsMapReaderTests : public ::testing::Test{

protected:

    void SetUp(){

        char * buffer;
        int size = readFile("tests/res/correct_coords.json", &buffer);

        res = coordsMapReader.readCoordsMap(buffer, size, coordsMap);

        free(buffer);
    }

    void TearDown(){
    }

    tiger::trains::convertors::json::CoordsMapReader coordsMapReader;
    std::vector<CoordModel> coordsMap;
    int res;

};


TEST_F(CoordsMapReaderTests, baseInfo){
    ASSERT_FALSE(res) << coordsMapReader.getLastErrorMessage();
    ASSERT_EQ(12u, coordsMap.size());
}


TEST_F(CoordsMapReaderTests, pointIdx){
    for (size_t i=0; i<coordsMap.size(); i++)
        ASSERT_EQ((int)i * 4 + 4, coordsMap[i].idx);
}


TEST_F(CoordsMapReaderTests, somePoints){
    ASSERT_EQ(2, coordsMap[3].x);
    ASSERT_EQ(5, coordsMap[3].y);

    ASSERT_EQ(1, coordsMap[5].x);
    ASSERT_EQ(30, coordsMap[5].y);

    ASSERT_EQ(65, coordsMap[8].x);
    ASSERT_EQ(43, coordsMap[8].y);
}
