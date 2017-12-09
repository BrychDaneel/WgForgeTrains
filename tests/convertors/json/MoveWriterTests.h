#include <gtest/gtest.h>
#include <convertors/json/MoveWriter.h>
#include <string>
#include <nlohmann/json.hpp>


using namespace testing;


using tiger::trains::models::SpeedType;
using std::string;


#include <convertors/IMoveWriter.h>


TEST(MoveWriteTests, forward){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::MoveModel move(2, 33, SpeedType::FORWARD);
    moveWriter.writeMove(&move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3u);
    ASSERT_EQ(j["train_idx"], 33);
    ASSERT_EQ(j["line_idx"], 2);
    ASSERT_EQ(j["speed"], 1);
}


TEST(MoveWriteTests, stop){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::MoveModel move(55, 354, SpeedType::STOP);
    moveWriter.writeMove(&move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3u);
    ASSERT_EQ(j["train_idx"], 354);
    ASSERT_EQ(j["line_idx"], 55);
    ASSERT_EQ(j["speed"], 0);
}


TEST(MoveWriteTests, reverse){
    tiger::trains::convertors::json::MoveWriter moveWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::MoveModel move(4, 5, SpeedType::REVERSE);
    moveWriter.writeMove(&move, buffer, &size);
    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_EQ(j.size(), 3u);
    ASSERT_EQ(j["train_idx"], 5);
    ASSERT_EQ(j["line_idx"], 4);
    ASSERT_EQ(j["speed"], -1);
}
