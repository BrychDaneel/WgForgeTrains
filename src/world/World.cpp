#include <world/World.h>
#include <world/PostFactory.h>


namespace tiger{
namespace trains{
namespace world{

    void World::clearPosts(){
        for (IPost * post : getPostList())
            delete post;
    }


    void World::init(const std::vector<models::PlayerModel>& playerList, const models::StaticMap& staticMap){

        for (models::PointModel pointModel : staticMap.getPointList()){
            Point point(pointModel, this);
            pointMap[pointModel.getIdx()] = point;
            std::vector<Line*> v;
            graph[&point] = v;

            if (pointModel.hasPost()){
                postOfPoint[&point] = pointModel.getPostId();
                pointOfPost[pointModel.getPostId()] = &point;
            }
        }

        for (models::LineModel lineModel : staticMap.getLineList()){
            Line line(lineModel, this);
            lineMap[lineModel.getIdx()] = line;
            graph[line.getStartPont()].push_back(&line);
            graph[line.getEndPont()].push_back(&line);
        }

        for (models::PlayerModel playerModel : playerList){
            Player player(playerModel, this);
            playerMap[playerModel.getIdx()] = player;
            homes[&player] = playerModel.getHome();
        }

    }

    void World::update(const models::DynamicMap& dynamicMap){
        for (models::PostModel postModel : dynamicMap.getPostList()){
            if (postMap.find(postModel.getIdx()) == postMap.end())
                postMap[postModel.getIdx()] = PostFactory::createPost(postModel, this);
            else
                postMap[postModel.getIdx()]->update(postModel);
        }
    }

    const std::vector<Player*>& World::getPlayerList() const{
    }

    const std::vector<Train*>& World::getTrainList() const{
    }

    const std::vector<IPost*>& World::getPostList() const{
    }

    const std::vector<Point*>& World::getPointList() const{
    }

    const std::vector<Line*>& World::getLineList() const{
    }

    Player* World::getPlayerByIdx(std::string idx) const{
    }

    Train* World::getTrainByIdx(int idx) const{
    }

    IPost* World::getPostByIdx(int idx) const{
    }

    Point* World::getPointByIdx(int idx) const{
    }

    Line* World::getLineByIdx(int idx) const{
    }

    const std::vector<Line*>& World::getEdges(Point* point) const{
    }

    IPost* World::getPostOfPoint(Point* point) const{
    }

    Point* World::getPointOfPost(IPost* post) const{
    }

    const std::vector<Train*>& World::getTrainsOfPlayer(Player * player) const{
    }

    IPost* World::getHome(Player* player) const{
    }

    const std::vector<Train*>& World::getTrainsOfLine(Line* line) const{
    }

}
}
}
