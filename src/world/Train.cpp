#include <world/Train.h>
#include <easylogging++/easylogging++.h>
#include <cmath>


namespace tiger
{
namespace trains
{
namespace world
{


Train::Train()
{
}


Train::Train(const models::TrainModel& model, World* world)
{
    owner = world;

    idx = model.getIdx();
    player = owner->getPlayerByIdx(model.getPlayerIdx());

    update(model);
}


void Train::update(models::TrainModel model)
{
    line = owner->getLineByIdx(model.getLineIdx());

    speed = model.getSpeed();
    position = model.getPosition();
    goodsCapacity = model.getGoodsCapacity();
    goods = model.getGoods();

    goodsType = model.getGoodsType();
    level = model.getLevel();
    nextLevelPrice = model.getNextLevelPrice();
}


World* Train::getWorld() const
{
    return owner;
}


int Train::getIdx() const
{
    return idx;
}


Player* Train::getPlayer() const
{
    return player;
}


Line* Train::getLine() const
{
    return line;
}


int Train::getPosition() const
{
    return position;
}


int Train::getGoodsCapacity() const
{
    return goodsCapacity;
}


int Train::getGoods() const
{
    return goods;
}


Point *Train::getPoint() const
{

    if (line == nullptr){
        return player->getHome()->getPoint();
    }

    if (position == 0){

        return line->getStartPont();
    }

    if (position == line->getLenght())
    {
        return line->getEndPont();
    }

    return nullptr;

}

models::SpeedType Train::getSpeed() const
{
    return speed;
}


void Train::move(Line* line, models::SpeedType speed){
    models::MoveModel moveModel(line->getIdx(), idx, speed);
    owner->getCommandSender()->move(moveModel);
}


void Train::addEvent(IEvent* event)
{
    eventsHistory.push_back(event);
}


void Train::clearEvents(){
    eventsHistory.clear();
}


const std::vector<IEvent*>& Train::getEvents() const
{
    return eventsHistory;
}


models::GoodType Train::getGoodsType() const
{
    return goodsType;
}


int Train::getLevel() const
{
    return level;
}


int Train::getNextLevelPrice() const
{
    return nextLevelPrice;
}


bool Train::upgrade() const
{
    return (owner->getCommandSender()->upgrade(models::UpgradeModel({idx},{})));
}

std::vector<Train*> Train::getPosibleCollisions(const models::MoveModel* move)
{
    int pos = position;
    const Line* lin = line;

    if (move!=nullptr){
        if (move->getLineIdx() != lin->getIdx()){

            if (getPoint() == nullptr){
                LOG(ERROR) << "Bad move command for predictions.";
                return std::vector<Train*>();
            }

            std::vector<Line*> edges = getPoint()->getEdges();
            if (std::find(edges.begin(), edges.end(), owner->getLineByIdx(move->getLineIdx())) == edges.end()){
                LOG(ERROR) << "Bad move command for predictions.";
                return std::vector<Train*>();
            }

            lin = owner->getLineByIdx(move->getLineIdx());
            pos = lin->getStartPont() == getPoint() ? 0 : lin->getLenght();
        }

        if (move->getSpeedType() == models::SpeedType::FORWARD){
            if (pos == lin->getLenght()){
                LOG(ERROR) << "Bad move command for predictions.";
                return std::vector<Train*>();
            }

            pos++;
        }

        if (move->getSpeedType() == models::SpeedType::REVERSE){
            if (pos == 0){
                LOG(ERROR) << "Bad move command for predictions.";
                return std::vector<Train*>();
            }

            pos--;
        }
    }

    std::vector<Train*> res;

    for (Train* train : line->getTrains())
        if (train != this){
            if (abs(pos - train->getPosition()) < 2)
                res.push_back(train);
        }

    Point* point = nullptr;

    if (pos == 0)
        point = lin->getStartPont();

    if (pos == lin->getLenght())
        point = lin->getStartPont();

    if (point)
        for (Line* edg: point->getEdges())
            for (Train* train : edg->getTrains()){
                if (edg->getStartPont() == point && train->getPosition() < 2)
                    res.push_back(train);
                if (edg->getEndPont() == point && train->getPosition() > edg->getLenght() - 2)
                    res.push_back(train);
            }

    if (pos < 2)
        for (Train* train : lin->getStartPont()->getTrains())
            res.push_back(train);

    if (pos > lin->getLenght() - 2)
        for (Train* train : lin->getEndPont()->getTrains())
            res.push_back(train);

    return res;
}


}
}
}
