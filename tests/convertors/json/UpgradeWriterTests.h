#include <gtest/gtest.h>
#include <convertors/json/UpgradeWriter.h>
#include <string>
#include <nlohmann/json.hpp>


using namespace testing;

using std::string;


TEST(UpgradeWriteTests, oneTrain){
    tiger::trains::convertors::json::UpgradeWriter upgradeWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::UpgradeModel upgrade({1},{});


    if(upgradeWriter.writeUpgrade(&upgrade, buffer, &size))
        FAIL() << upgradeWriter.getLastErrorMessage();

    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_TRUE(j["train"].is_array());
    ASSERT_TRUE(j["post"].is_array());
    ASSERT_EQ(j["train"].size(), 1u);
    ASSERT_EQ(j["post"].size(), 0u);

    ASSERT_EQ(j["train"][0], 1);
}


TEST(UpgradeWriteTests, onePost){
    tiger::trains::convertors::json::UpgradeWriter upgradeWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::UpgradeModel upgrade({},{5});

    ASSERT_FALSE(upgradeWriter.writeUpgrade(&upgrade, buffer, &size));

    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j.is_object());
    ASSERT_TRUE(j["train"].is_array());
    ASSERT_TRUE(j["post"].is_array());
    ASSERT_EQ(j["train"].size(), 0u);
    ASSERT_EQ(j["post"].size(), 1u);

    ASSERT_EQ(j["post"][0], 5);
}


TEST(UpgradeWriteTests, full){
    tiger::trains::convertors::json::UpgradeWriter upgradeWriter;
    char buffer[100];
    int size = 100;
    tiger::trains::models::UpgradeModel upgrade({1, 2, 4},{3, 5, 7});

    ASSERT_FALSE(upgradeWriter.writeUpgrade(&upgrade, buffer, &size));

    string str;
    str.assign(buffer, size);

    nlohmann::json j = nlohmann::json::parse(str);

    ASSERT_TRUE(j["train"].is_array());
    ASSERT_TRUE(j["post"].is_array());
    ASSERT_EQ(j["train"].size(), 3u);
    ASSERT_EQ(j["post"].size(), 3u);

    ASSERT_EQ(j["train"][0], 1);
    ASSERT_EQ(j["train"][1], 2);
    ASSERT_EQ(j["train"][2], 4);

    ASSERT_EQ(j["post"][0], 3);
    ASSERT_EQ(j["post"][1], 5);
    ASSERT_EQ(j["post"][2], 7);
}
