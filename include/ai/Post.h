#ifndef _AI_POST_H_
#define _AI_POST_H_

#include <world/World.h>
#include <vector>
#include <map>
namespace tiger {
namespace trains {
namespace ai {


class Post
{
public:
    Post(world::Point *point);
    void init(const world::World &world);
    int getMinLen(const world::Point *point) const;
    const world::Point *getPoint() const;
    std::vector<const world::Point*> getMinPath(const world::Point *point) const;
    std::vector<const world::Point *> getMinPathOnlyPost(const world::Point *point) const;

private:
    const world::Point *postPoint;
    mutable std::map<const world::Point*, int> minLen;
    mutable std::map<const world::Point*, const world::Point*> ancestors;
    const int inf = 999999;


};

}

}

}



#endif
