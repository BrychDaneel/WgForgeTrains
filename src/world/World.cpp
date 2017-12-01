#include <world/World.h>
#include <world/PostFactory.h>


using namespace tiger::trains::world;


World::~World(){
    for (IPost* post : getPostList())
        delete post;

    for (Train* train : getTrainList())
        delete train;

    for (Player* player : getPlayerList())
        delete player;

    for (Point* point : getPointList())
        delete point;

    for (Line* line : getLineList())
        delete line;
}


void World::init(const std::vector<models::PlayerModel>& playerModelList, const models::StaticMap& staticMap,
                 ICommandSender* commandSender)
{

    this->commandSender = commandSender;

    for (models::PointModel pointModel : staticMap.getPointList()){
        Point* point = new Point(pointModel, this);
        pointMap[pointModel.getIdx()] = point;
        pointList.push_back(point);

        std::vector<Line*> v;
        graph[point] = v;

        if (pointModel.hasPost()){
            postOfPoint[point] = pointModel.getPostId();
            pointOfPost[pointModel.getPostId()] = point;
        }
    }


    for (models::LineModel lineModel : staticMap.getLineList()){
        Line* line = new Line(lineModel, this);
        lineMap[lineModel.getIdx()] = line;
        lineList.push_back(line);
        graph[line->getStartPont()].push_back(line);
        graph[line->getEndPont()].push_back(line);

        trainsOfLine[line] = std::vector<Train*>();
    }

    for (models::PlayerModel playerModel : playerModelList){
        Player* player = new Player(playerModel, this);
        playerMap[playerModel.getIdx()] = player;
        playerList.push_back(player);
        homes[player] = playerModel.getHome();
    }

    initialized = true;
}


void World::update(const models::DynamicMap& dynamicMap){

    for (models::PostModel postModel : dynamicMap.getPostList()){
        if (postMap.find(postModel.getIdx()) == postMap.end()){
            IPost* post = PostFactory::createPost(postModel, this);
            postMap[postModel.getIdx()] = post;
            postList.push_back(post);
        } else
            postMap[postModel.getIdx()]->update(postModel);
    }

    for (auto trainList = trainsOfLine.begin(); trainList != trainsOfLine.end(); trainList++)
        trainList->second.clear();

    for (models::TrainModel trainModel : dynamicMap.getTrainList()){
        if (trainMap.find(trainModel.getIdx()) == trainMap.end()){
            Train* train = new Train(trainModel, this);
            trainMap[trainModel.getIdx()] = train;
            trainList.push_back(train);
            trainsOfPlayer[playerMap[trainModel.getPlayerIdx()]].push_back(train);
        } else
            trainMap[trainModel.getIdx()]->update(trainModel);

        if (trainModel.isInLine())
            trainsOfLine[lineMap[trainModel.getLineIdx()]].push_back( trainMap[trainModel.getIdx()] );

    }
}


bool World::isInitialized(){
    return initialized;
}


int World::getTickNum(){
    return tickNum;
}


void World::setTickNum(const int tickNum){
    this->tickNum = tickNum;
}


void World::tick(){
    this->tickNum++;
}


ICommandSender* World::getCommandSender() const{
    return commandSender;
}


const std::vector<Player*>& World::getPlayerList() const{
    return playerList;
}


const std::vector<Train*>& World::getTrainList() const{
    return trainList;
}


const std::vector<IPost*>& World::getPostList() const{
    return postList;
}


const std::vector<Point*>& World::getPointList() const{
    return pointList;
}


const std::vector<Line*>& World::getLineList() const{
    return lineList;
}


Player* World::getPlayerByIdx(const std::string idx) const{
    return playerMap.find(idx)->second;
}


Train* World::getTrainByIdx(int idx) const{
    return trainMap.find(idx)->second;
}


IPost* World::getPostByIdx(int idx) const{
    return postMap.find(idx)->second;
}


Point* World::getPointByIdx(int idx) const{
    return pointMap.find(idx)->second;
}


Line* World::getLineByIdx(int idx) const{
    return lineMap.find(idx)->second;
}


const std::vector<Line*>& World::getEdges(const Point* point) const{
    return graph.find(point)->second;
}


IPost* World::getPostOfPoint(const Point* point) const{
    if (postOfPoint.find(point) == postOfPoint.end())
        return nullptr;
    else
        return getPostByIdx(postOfPoint.find(point)->second);
}


Point* World::getPointOfPost(const IPost* post) const{
    return pointOfPost.find(post->getIdx())->second;
}


const std::vector<Train*>& World::getTrainsOfPlayer(const Player* player) const{
    return trainsOfPlayer.find(player)->second;
}


IPost* World::getHome(const Player* player) const{
    return getPostByIdx(homes.find(player)->second);
}


const std::vector<Train*>& World::getTrainsOfLine(const Line* line) const{
    return trainsOfLine.find(line)->second;
}
