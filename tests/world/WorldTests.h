#include <gtest/gtest.h>
#include <convertors/json/StaticMapReader.h>
#include <string>
#include <models/StaticMap.h>
#include <models/DynamicMap.h>
#include <models/PlayerModel.h>
#include <vector>
#include <world/World.h>


using namespace testing;
using namespace tiger::trains::models;
using namespace tiger::trains::world;


TEST(WorldTests, playerList){
    std::vector<PlayerModel> v;
    v.push_back(PlayerModel("123", 42, "Ivan"));
    v.push_back(PlayerModel("22", 32, "Vasya"));
    v.push_back(PlayerModel("432", 22, "Petya"));

    StaticMap staticMap;

    World world;
    world.init(v, staticMap);

    ASSERT_EQ(3u, world.getPlayerList().size());

    ASSERT_EQ("123", world.getPlayerList()[0]->getIdx());
    ASSERT_EQ("22", world.getPlayerList()[1]->getIdx());
    ASSERT_EQ("432", world.getPlayerList()[2]->getIdx());

    ASSERT_EQ("Ivan", world.getPlayerByIdx("123")->getName());
    ASSERT_EQ("Vasya", world.getPlayerByIdx("22")->getName());
    ASSERT_EQ("Petya", world.getPlayerByIdx("432")->getName());
}


TEST(WorldTests, pointList){
    StaticMap staticMap;

    staticMap.addPoint(PointModel(33, ~0));
    staticMap.addPoint(PointModel(3, ~0));
    staticMap.addPoint(PointModel(5, 2));
    staticMap.addPoint(PointModel(1, 1));

    std::vector<PlayerModel> v;
    World world;
    world.init(v, staticMap);

    ASSERT_EQ(4u, world.getPointList().size());

    ASSERT_EQ(33, world.getPointList()[0]->getIdx());
    ASSERT_EQ(3, world.getPointList()[1]->getIdx());
    ASSERT_EQ(5, world.getPointList()[2]->getIdx());
    ASSERT_EQ(1, world.getPointList()[3]->getIdx());

    ASSERT_EQ(33, world.getPointByIdx(33)->getIdx());
    ASSERT_EQ(3, world.getPointByIdx(3)->getIdx());
    ASSERT_EQ(5, world.getPointByIdx(5)->getIdx());
    ASSERT_EQ(1, world.getPointByIdx(1)->getIdx());
}


TEST(WorldTests, lineList){
    StaticMap staticMap;

    staticMap.addLine(LineModel(1, 10, 1, 2));
    staticMap.addLine(LineModel(2, 20, 3, 4));
    staticMap.addLine(LineModel(4, 40, 3, 4));
    staticMap.addLine(LineModel(8, 80, 4, 5));

    std::vector<PlayerModel> v;
    World world;
    world.init(v, staticMap);

    ASSERT_EQ(4u, world.getLineList().size());

    ASSERT_EQ(1, world.getLineList()[0]->getIdx());
    ASSERT_EQ(2, world.getLineList()[1]->getIdx());
    ASSERT_EQ(4, world.getLineList()[2]->getIdx());
    ASSERT_EQ(8, world.getLineList()[3]->getIdx());

    ASSERT_EQ(1, world.getLineByIdx(1)->getIdx());
    ASSERT_EQ(2, world.getLineByIdx(2)->getIdx());
    ASSERT_EQ(4, world.getLineByIdx(4)->getIdx());
    ASSERT_EQ(8, world.getLineByIdx(8)->getIdx());
}


TEST(WorldTests, postList){
    DynamicMap dynamicMap;

    dynamicMap.addPost(PostModel(1, PostType::MARKET, 1, "M1", 10, 3, 1, 20));
    dynamicMap.addPost(PostModel(2, PostType::MARKET, 1, "M2", 10, 3, 1, 20));
    dynamicMap.addPost(PostModel(3, PostType::MARKET, 1, "M3", 10, 3, 1, 20));
    dynamicMap.addPost(PostModel(4, PostType::TOWN, 1, "T1", 10, 3, 1, 20));

    World world;
    world.init(std::vector<PlayerModel>(), StaticMap());
    world.update(dynamicMap);

    ASSERT_EQ(4u, world.getPostList().size());

    ASSERT_EQ(1, world.getPostList()[0]->getIdx());
    ASSERT_EQ(2, world.getPostList()[1]->getIdx());
    ASSERT_EQ(3, world.getPostList()[2]->getIdx());
    ASSERT_EQ(4, world.getPostList()[3]->getIdx());

    ASSERT_EQ("M1", world.getPostByIdx(1)->getName());
    ASSERT_EQ("M2", world.getPostByIdx(2)->getName());
    ASSERT_EQ("M3", world.getPostByIdx(3)->getName());
    ASSERT_EQ("T1", world.getPostByIdx(4)->getName());
}


TEST(WorldTests, trainList){
    DynamicMap dynamicMap;

    dynamicMap.addTrain(TrainModel(1, 2, "abc", 0, 15, 15, SpeedType::STOP));
    dynamicMap.addTrain(TrainModel(2, 8, "abc", 7, 13, 13, SpeedType::FORWARD));

    World world;
    world.init(std::vector<PlayerModel>({PlayerModel("abc", 1, "dno")}), StaticMap());
    world.update(dynamicMap);

    ASSERT_EQ(2u, world.getTrainList().size());

    ASSERT_EQ(1, world.getTrainList()[0]->getIdx());
    ASSERT_EQ(2, world.getTrainList()[1]->getIdx());

    ASSERT_EQ(1, world.getTrainByIdx(1)->getIdx());
    ASSERT_EQ(2, world.getTrainByIdx(2)->getIdx());
}


TEST(WorldTests, graph){
    StaticMap staticMap;

    staticMap.addPoint(PointModel(1, ~0));
    staticMap.addPoint(PointModel(2, ~0));
    staticMap.addPoint(PointModel(3, 2));
    staticMap.addPoint(PointModel(4, 3));

    staticMap.addLine(LineModel(1, 10, 1, 2));
    staticMap.addLine(LineModel(2, 20, 2, 3));
    staticMap.addLine(LineModel(4, 40, 2, 4));
    staticMap.addLine(LineModel(8, 80, 4, 5));


    World world;
    world.init(std::vector<PlayerModel>(), staticMap);

    std::vector<Line*> edges = world.getEdges(world.getPointByIdx(1));
    ASSERT_EQ(1u, edges.size());
    ASSERT_EQ(1, edges[0]->getIdx());

    edges = world.getEdges(world.getPointByIdx(2));
    ASSERT_EQ(3u, edges.size());
    ASSERT_EQ(1, edges[0]->getIdx());
    ASSERT_EQ(2, edges[1]->getIdx());
    ASSERT_EQ(4, edges[2]->getIdx());

}


TEST(WorldTests, isInit){
    World world;
    ASSERT_FALSE(world.isInitialized());
    world.init(std::vector<PlayerModel>(), StaticMap());
    ASSERT_TRUE(world.isInitialized());
}


TEST(WorldTests, postAndPoint){
    StaticMap staticMap;
    staticMap.addPoint(PointModel(1, 3));
    staticMap.addPoint(PointModel(2, 4));

    DynamicMap dynamicMap;
    dynamicMap.addPost(PostModel(3, PostType::TOWN, 1, "T1", 10, 3, 1, 20));
    dynamicMap.addPost(PostModel(4, PostType::MARKET, 1, "M2", 10, 3, 1, 20));

    World world;
    world.init(std::vector<PlayerModel>(), staticMap);
    world.update(dynamicMap);

    Point* point1 = world.getPointByIdx(1);
    Point* point2 = world.getPointByIdx(2);

    IPost* post1 = world.getPostByIdx(3);
    IPost* post2 = world.getPostByIdx(4);

    ASSERT_EQ(point1, world.getPointOfPost(post1));
    ASSERT_EQ(point2, world.getPointOfPost(post2));

    ASSERT_EQ(post1, world.getPostOfPoint(point1));
    ASSERT_EQ(post2, world.getPostOfPoint(point2));
}


TEST(WorldTests, home){
    StaticMap staticMap;
    staticMap.addPoint(PointModel(1, 4));

    DynamicMap dynamicMap;
    dynamicMap.addPost(PostModel(4, PostType::TOWN, 1, "T1", 10, 3, 1, 20));

    std::vector<PlayerModel> players({PlayerModel("abc", 4, "dno")});

    World world;
    world.init(players, staticMap);
    world.update(dynamicMap);

    Player* player = world.getPlayerByIdx("abc");
    ASSERT_NE(nullptr, player);

    IPost* post = world.getHome(player);
    ASSERT_NE(nullptr, post);
    ASSERT_EQ(4, post->getIdx());

}


TEST(WorldTests, playerTrains){

    DynamicMap dynamicMap;
    dynamicMap.addTrain(TrainModel(1, 2, "abc", 0, 15, 15, SpeedType::STOP));
    dynamicMap.addTrain(TrainModel(2, 2, "abc", 0, 15, 15, SpeedType::STOP));

    std::vector<PlayerModel> players({PlayerModel("abc", 4, "dno")});

    World world;
    world.init(players, StaticMap());
    world.update(dynamicMap);

    Player* player = world.getPlayerByIdx("abc");
    ASSERT_EQ(2u, world.getTrainsOfPlayer(player).size());

    ASSERT_EQ(1, world.getTrainsOfPlayer(player)[0]->getIdx());
    ASSERT_EQ(2, world.getTrainsOfPlayer(player)[1]->getIdx());

}


TEST(WorldTests, lineTrains){

    StaticMap staticMap;

    staticMap.addPoint(PointModel(1, ~0));
    staticMap.addPoint(PointModel(2, ~0));

    staticMap.addLine(LineModel(1, 10, 1, 2));

    DynamicMap dynamicMap;
    dynamicMap.addTrain(TrainModel(1, 2, "abc", 0, 15, 15, SpeedType::STOP));
    dynamicMap.addTrain(TrainModel(2, 2, "abc", 0, 15, 15, SpeedType::STOP));

    std::vector<PlayerModel> players({PlayerModel("abc", 4, "dno")});

    World world;
    world.init(players, staticMap);
    world.update(dynamicMap);

    Line* line = world.getLineByIdx(2);

    std::vector<Train*> trains = world.getTrainsOfLine(line);

    ASSERT_EQ(2u, trains.size());
    ASSERT_EQ(1, trains[0]->getIdx());
    ASSERT_EQ(2, trains[1]->getIdx());
}
