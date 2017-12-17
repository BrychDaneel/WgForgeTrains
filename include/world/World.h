#pragma once
#ifndef _TIGER_TRAINS_WORLD_WORLD_H_
#define _TIGER_TRAINS_WORLD_WORLD_H_


#include <world/ICommandSender.h>
#include <world/Point.h>
#include <world/Line.h>
#include <world/Player.h>
#include <world/Train.h>
#include <world/IPost.h>
#include <world/PostFactory.h>
#include <world/IEvent.h>
#include <world/EventFactory.h>

#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>
#include <models/CoordsMap.h>

#include <map>
#include <vector>
#include <string>


namespace tiger{
namespace trains{
namespace world{


class Point;
class Line;
class Player;
class Train;
class IPost;
class PostFactory;
class IEvent;


class World{

private:

    ICommandSender* commandSender;

    bool initialized = false;
    bool gameOver = false;

    int tickNum = 0;

    std::map<Player*, int> scoreMap;

    std::map<int, IPost*> postMap;
    std::map<std::string, Player*> playerMap;
    std::map<int, Point*> pointMap;
    std::map<int, Line*> lineMap;
    std::map<int, Train*> trainMap;

    std::vector<Player*> playerList;
    std::vector<Train*> trainList;
    std::vector<IPost*> postList;
    std::vector<Point*> pointList;
    std::vector<Line*> lineList;

    std::map<const Point*, std::vector<Line*> > graph;
    std::map<const Player*, int> homes;

    std::map<std::string, Player*> playerOfName;
    std::map<const Point*, int> postOfPoint;
    std::map<int, Point*> pointOfPost;
    std::map<const Line*, std::vector<Train*> > trainsOfLine;
    std::map<const Player*, std::vector<Train*> > trainsOfPlayer;

    std::vector<std::vector<IEvent*> > eventsHistory;

    void fillEventsHistory(const size_t size);

    int width = 0;
    int height = 0;

public:

    virtual ~World();

    void init(const std::vector<models::PlayerModel>& playerModelList, const models::StaticMap& staticMap,
              ICommandSender* commandSender=nullptr);

    void update(const models::DynamicMap& dynamicMap);
    void setCoords(const models::CoordsMap& coordsMap);

    bool isInitialized();
    bool hasCoords();

    int getTickNum();
    void setTickNum(const int tick);
    void tick();

    ICommandSender* getCommandSender() const;

    const std::vector<Player*>& getPlayerList() const;
    const std::vector<Train*>& getTrainList() const;
    const std::vector<IPost*>& getPostList() const;
    const std::vector<Point*>& getPointList() const;
    const std::vector<Line*>& getLineList() const;

    Player* getPlayerByName(const std::string name) const;

    Player* getPlayerByIdx(const std::string idx) const;
    Train* getTrainByIdx(int idx) const;
    IPost* getPostByIdx(int idx) const;
    Point* getPointByIdx(int idx) const;
    Line* getLineByIdx(int idx) const;

    const std::vector<Line*>& getEdges(const Point* point) const;
    Line* getLine(const Point* point1, const Point* point2);

    IPost* getPostOfPoint(const Point* point) const;
    Point* getPointOfPost(const IPost* post) const;

    const std::vector<Train*>& getTrainsOfPlayer(const Player* player) const;
    IPost* getHome(const Player* player) const;

    const std::vector<Train*>& getTrainsOfLine(const Line* line) const;


    const std::vector<std::vector<IEvent*> > & getEventsHistory() const;
    const std::vector<IEvent*>& getEvents(int tick) const;
    const std::vector<IEvent*> getEventsAfter(int startTick) const;

    int getWidth() const;
    int getHeight() const;

    bool isGameOver();

    int getScore(Player* player);
};


}
}
}


#endif
