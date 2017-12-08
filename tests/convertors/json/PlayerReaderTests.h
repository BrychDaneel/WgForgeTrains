#include <gtest/gtest.h>
#include <convertors/json/PlayerReader.h>
#include <string>
#include <fstream>
#include <tests/reader.h>

using namespace testing;


TEST(PlayerTest, correct)
{

    tiger::trains::convertors::json::PlayerReader playerReader;

    char * buffer;
    int size = readFile("tests/res/correct_player.json", &buffer);

    tiger::trains::models::PlayerModel player;
    int res = playerReader.readPlayer(buffer, size, &player);

    free(buffer);

    ASSERT_FALSE(res);
    ASSERT_EQ(8, player.getHome());
    ASSERT_EQ("c8e35156-de2f-4690-be43-cccbc116e513", player.getIdx());
    ASSERT_EQ("tiger", player.getName());
}


TEST(PlayerTest, null)
{

    tiger::trains::convertors::json::PlayerReader playerReader;

    char * buffer;
    int size = readFile("tests/res/null_player.json", &buffer);

    tiger::trains::models::PlayerModel player;
    int res = playerReader.readPlayer(buffer, size, &player);

    free(buffer);

    ASSERT_EQ(4, res);
}
