#pragma once
#ifndef _TIGER_TRAINS_WORLD_WORLD_H_
#define _TIGER_TRAINS_WORLD_WORLD_H_


#include <world/Point.h>
#include <world/Line.h>
#include <world/Player.h>
#include <world/Train.h>
#include <world/IPost.h>
#include <world/PostFactory.h>

#include <models/DynamicMap.h>
#include <models/StaticMap.h>
#include <models/PlayerModel.h>

#include <map>
#include <vector>
#include <string>


namespace tiger{
namespace trains{
namespace world{

    class World{
        private:
            std::map<int, IPost*> postMap;
            std::map<std::string, Player> playerMap;
            std::map<int, Point> pointMap;
            std::map<int, Line> lineMap;
            std::map<int, Train> trainMap;

            std::map<Point*, std::vector<Line*> > graph;
            std::map<Player*, int> homes;

            std::map<Line*, std::vector<Train*> > trainsOfLine;
            std::map<Point*, int> postOfPoint;
            std::map<int, Point*> pointOfPost;
            std::map<Player*, std::vector<Train*> > trainsOfPlayer;

            void clearPosts();

        public:
            void init(const std::vector<models::PlayerModel>& playerList, const models::StaticMap& staticMap);
            void update(const models::DynamicMap& dynamicMap);

            const std::vector<Player*>& getPlayerList() const;
            const std::vector<Train*>& getTrainList() const;
            const std::vector<IPost*>& getPostList() const;
            const std::vector<Point*>& getPointList() const;
            const std::vector<Line*>& getLineList() const;

            Player* getPlayerByIdx(std::string idx) const;
            Train* getTrainByIdx(int idx) const;
            IPost* getPostByIdx(int idx) const;
            Point* getPointByIdx(int idx) const;
            Line* getLineByIdx(int idx) const;

            const std::vector<Line*>& getEdges(Point* point) const;
            IPost* getPostOfPoint(Point* point) const;
            Point* getPointOfPost(IPost* post) const;
            const std::vector<Train*>& getTrainsOfPlayer(Player * player) const;
            IPost* getHome(Player* player) const;
            const std::vector<Train*>& getTrainsOfLine(Line* line) const;
    };
}
}
}



#endif
