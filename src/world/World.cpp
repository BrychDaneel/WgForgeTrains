#include <world/World.h>
#include <world/PostFactory.h>


using namespace tiger::trains::world;


World::~World()
{
    for (IPost *post : getPostList())
        delete post;

    for (Train *train : getTrainList())
        delete train;

    for (Player *player : getPlayerList())
        delete player;

    for (Point *point : getPointList())
        delete point;

    for (Line *line : getLineList())
        delete line;

    for (std::vector<IEvent *> &eventList : eventsHistory)
        for (IEvent *event : eventList)
            delete event;
}


void World::init(const std::vector<models::PlayerModel> &playerModelList, const models::StaticMap &staticMap,
                 ICommandSender *commandSender)
{

    gameOver = false;

    this->commandSender = commandSender;

    for (models::PointModel pointModel : staticMap.getPointList())
    {
        Point *point = new Point(pointModel, this);
        pointMap[pointModel.getIdx()] = point;
        pointList.push_back(point);

        std::vector<Line *> v;
        graph[point] = v;

        if (pointModel.hasPost())
        {
            postOfPoint[point] = pointModel.getPostId();
            pointOfPost[pointModel.getPostId()] = point;
        }
    }


    for (models::LineModel lineModel : staticMap.getLineList())
    {
        Line *line = new Line(lineModel, this);
        lineMap[lineModel.getIdx()] = line;
        lineList.push_back(line);
        graph[line->getStartPont()].push_back(line);
        graph[line->getEndPont()].push_back(line);

        trainsOfLine[line] = std::vector<Train *>();
    }

    for (models::PlayerModel playerModel : playerModelList)
    {
        Player *player = new Player(playerModel, this);
        playerMap[playerModel.getIdx()] = player;
        playerOfName[playerModel.getName()] = player;
        playerList.push_back(player);
        homes[player] = playerModel.getHome();
    }

    width = 0;
    height = 0;
    initialized = true;
}


void World::fillEventsHistory(const size_t size)
{
    while (eventsHistory.size() < size)
        eventsHistory.push_back(std::vector<IEvent *>());
}


void World::update(const models::DynamicMap &dynamicMap)
{
    for (models::PostModel postModel : dynamicMap.getPostList())
    {
        if (postMap.find(postModel.getIdx()) == postMap.end())
        {
            IPost *post = PostFactory::createPost(postModel, this);
            postMap[postModel.getIdx()] = post;
            postList.push_back(post);
        }
        else
            postMap[postModel.getIdx()]->update(postModel);

        for (models::EventModel eventModel : postModel.getEventList())
        {
            IPost *post = postMap[postModel.getIdx()];
            IEvent *event = EventFactory::createEvent(eventModel, post);

            if (event->getType() == models::EventType::GAME_OVER)
                gameOver = true;

            post->addEvent(event);
            fillEventsHistory(event->getTick() + 1);
            eventsHistory[event->getTick()].push_back(event);
        }
    }

    for (auto trainList = trainsOfLine.begin(); trainList != trainsOfLine.end(); trainList++)
        trainList->second.clear();

    for (models::TrainModel trainModel : dynamicMap.getTrainList())
    {
        if (playerMap.find(trainModel.getPlayerIdx()) == playerMap.end())
        {
            models::PlayerModel playerModel;
            playerModel.setName("DNO");
            playerModel.setIdx(trainModel.getPlayerIdx());
            playerModel.setHome(playerList[0]->getHome()->getPoint()->getIdx());
            Player *player = new Player(playerModel, this);
            playerMap[playerModel.getIdx()] = player;
            playerOfName[playerModel.getName()] = player;
            playerList.push_back(player);
            homes[player] = playerModel.getHome();
        }

        if (trainMap.find(trainModel.getIdx()) == trainMap.end())
        {
            Train *train = new Train(trainModel, this);
            trainMap[trainModel.getIdx()] = train;
            trainList.push_back(train);
            trainsOfPlayer[playerMap[trainModel.getPlayerIdx()]].push_back(train);
        }
        else
            trainMap[trainModel.getIdx()]->update(trainModel);

        trainsOfLine[lineMap[trainModel.getLineIdx()]].push_back( trainMap[trainModel.getIdx()] );

        for (models::EventModel eventModel : trainModel.getEventList())
        {
            Train *train = trainMap[trainModel.getIdx()];
            IEvent *event = EventFactory::createEvent(eventModel, train);

            if (event->getType() == models::EventType::GAME_OVER)
                gameOver = true;

            train->addEvent(event);
            fillEventsHistory(event->getTick() + 1);
            eventsHistory[event->getTick()].push_back(event);
        }

    }

    scoreMap.clear();

    for (auto it : dynamicMap.getScoreMap())
        scoreMap[getPlayerByName(it.first)] = it.second;
}


void World::setCoords(const models::CoordsMap &coordsMap)
{
    for (models::CoordModel coord : coordsMap.coords)
    {
        Point *point = getPointByIdx(coord.idx);
        point->setX(coord.x);
        point->setY(coord.y);
    }

    width = coordsMap.width;
    height = coordsMap.height;
}


bool World::isInitialized()
{
    return initialized;
}


int World::getTickNum()
{
    return tickNum;
}


void World::setTickNum(const int tickNum)
{
    this->tickNum = tickNum;
}


void World::tick()
{
    this->tickNum++;
}


ICommandSender *World::getCommandSender() const
{
    return commandSender;
}


const std::vector<Player *> &World::getPlayerList() const
{
    return playerList;
}


const std::vector<Train *> &World::getTrainList() const
{
    return trainList;
}


const std::vector<IPost *> &World::getPostList() const
{
    return postList;
}


const std::vector<Point *> &World::getPointList() const
{
    return pointList;
}


const std::vector<Line *> &World::getLineList() const
{
    return lineList;
}

Player *World::getPlayerByName(const std::string name) const
{
    return playerOfName.find(name)->second;
}


Player *World::getPlayerByIdx(const std::string idx) const
{
    return playerMap.find(idx)->second;
}


Train *World::getTrainByIdx(int idx) const
{
    return trainMap.find(idx)->second;
}


IPost *World::getPostByIdx(int idx) const
{
    return postMap.find(idx)->second;
}


Point *World::getPointByIdx(int idx) const
{
    return pointMap.find(idx)->second;
}


Line *World::getLineByIdx(int idx) const
{
    return lineMap.find(idx)->second;
}


const std::vector<Line *> &World::getEdges(const Point *point) const
{
    return graph.find(point)->second;
}


Line *World::getLine(const Point *point1, const Point *point2)
{
    for (Line *line : point1->getEdges())
        if (line->getAnotherPoint(point1) == point2)
            return line;

    return nullptr;
}


IPost *World::getPostOfPoint(const Point *point) const
{
    if (postOfPoint.find(point) == postOfPoint.end())
        return nullptr;
    else
        return getPostByIdx(postOfPoint.find(point)->second);
}


Point *World::getPointOfPost(const IPost *post) const
{
    return pointOfPost.find(post->getIdx())->second;
}


const std::vector<Train *> &World::getTrainsOfPlayer(const Player *player) const
{
    return trainsOfPlayer.find(player)->second;
}


IPost *World::getHome(const Player *player) const
{
    return getPostByIdx(homes.find(player)->second);
}


const std::vector<Train *> &World::getTrainsOfLine(const Line *line) const
{
    return trainsOfLine.find(line)->second;
}


const std::vector<std::vector<IEvent *> > &World::getEventsHistory() const
{
    return eventsHistory;
}


const std::vector<IEvent *> &World::getEvents(int tick) const
{
    return eventsHistory[tick];
}


const std::vector<IEvent *> World::getEventsAfter(int startTick) const
{
    std::vector<IEvent *> res;

    for (size_t i=startTick; i<eventsHistory.size(); i++)
        for (IEvent *event: eventsHistory[i])
            res.push_back(event);

    return res;
}


int World::getWidth() const
{
    return width;
}


int World::getHeight() const
{
    return height;
}


bool World::isGameOver()
{
    return gameOver;
}

int World::getScore(Player *player)
{
    //return scoreMap[player];
    return 0;
}
