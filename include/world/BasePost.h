#pragma once
#ifndef _TIGER_TRAINS_WORLD_BASE_POST_H_
#define _TIGER_TRAINS_WORLD_BASE_POST_H_


#include <world/World.h>
#include <world/IPost.h>


namespace tiger{
namespace trains{
namespace world{


class World;


class BasePost : public IPost{

protected:

    World* owner;
    int idx;
    models::PostType type;
    std::string name;
    std::vector<IEvent*> eventsHistory;

public:

    ~BasePost();

    BasePost();
    BasePost(const models::PostModel& model, World* world);

    void update(const models::PostModel& model);

    World* getWorld() const;
    int getIdx() const;
    Point* getPoint() const;
    const std::string& getName() const;
    models::PostType getPostType() const;

    void addEvent(IEvent* event);
    void clearEvents();
    const std::vector<IEvent*>& getEvents() const;
};


}
}
}


#endif
