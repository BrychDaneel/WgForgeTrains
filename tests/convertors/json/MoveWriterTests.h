#include <gtest/gtest.h>
#include <convertors/json/MoveWriter.h>.h>
#include <string>
#include <nlohmann/json.hpp>


using namespace testing;


using tiger::trains::models::SpeedType;
using std::string;


#include <convertors/IMoveWriter.h>


TEST(MoveWriteTests, forward){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char[100] buffer;
    int size = 100;
    tiger::trains::models::MoveModel move(33, 2, SpeedType::FORWARD);
    moveWriter.writeMove(move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3);
    ASSERT_EQ(j["train_idx"], 33);
    ASSERT_EQ(j["line_idx"], 2);
    ASSERT_EQ(j["speed"], 1);
}


TEST(MoveWriteTests, stop){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char[100] buffer;
    int size = 100;
    tiger::trains::models::MoveModel move(354, 55, SpeedType::STOP);
    moveWriter.writeMove(move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3);
    ASSERT_EQ(j["train_idx"], 354);
    ASSERT_EQ(j["line_idx"], 55);
    ASSERT_EQ(j["speed"], 0);
}


TEST(MoveWriteTests, reverse){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char[100] buffer;
    int size = 100;
    tiger::trains::models::MoveModel move(5, 4, SpeedType::REVERSE);
    moveWriter.writeMove(move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3);
    ASSERT_EQ(j["train_idx"], 5);
    ASSERT_EQ(j["line_idx"], 4);
    ASSERT_EQ(j["speed"], 1);
}
