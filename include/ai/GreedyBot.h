#ifndef _GREEDY_BOT_H_
#define _GREEDY_BOT_H_

#include <CommandSender.h>
#include <world/World.h>
#include <ai/IBot.h>
#include <ai/Post.h>
#include <ai/ArtMarket.h>
#include <ai/ArtTown.h>
#include <map>
#include <vector>

namespace tiger
{
    namespace trains
    {
        namespace ai
        {

            class GreedyBot: public IBot
            {
                public:
                    GreedyBot();
                    void init(world::World *world);
                    void step();

                private:

                    world::World *world;
                    int tick;
                    std::map<int, Post*> postMap;
                    Post* homePost;
                    Post* currentPost;

                    Post *nextPost;
                    world::Line *currentLine;
                    std::vector<const world::Point*> currentPath;


                    void findNextPost();
                    void makeStep();
                    void checkArrival();


            };

        }
    }
}


#endif
