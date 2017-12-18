#include <world/PostFactory.h>


#include <world/BasePost.h>
#include <world/Town.h>
#include <world/Market.h>
#include <world/Storage.h>


namespace tiger
{
namespace trains
{
namespace world
{


IPost *PostFactory::createPost(const models::PostModel &model, World *world)
{
    switch (model.getType())
    {

    case models::PostType::TOWN:
        return new Town(model, world);

    case models::PostType::MARKET:
        return new Market(model, world);

    case models::PostType::STORAGE:
        return new Storage(model, world);

    default:
        return new BasePost(model, world);
    }
}


}
}
}
