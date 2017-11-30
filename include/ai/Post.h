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
    Post(const world::Point *point);
    void init(const world::World &world);
    int getMinLen(const world::Point *point);
    std::vector<const world::Point*> getMinPath(const world::Point *point);

private:
    const world::Point *postPoint;
    std::map<const world::Point*, int> minLen;
    std::map<const world::Point*, const world::Point*> ancestors;
    const int inf = 999999;


};

}

}

}



#endif
