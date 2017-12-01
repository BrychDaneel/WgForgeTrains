#include <ai/ScoreCalc.h>
#include <models/PostType.h>

using namespace tiger::trains::ai;

ScoreCalc::ScoreCalc(std::map<int, Post *> *postMap, const Post *startPost,const Post* homePost,int maxTick)
    :postMap(postMap), startPost(startPost), homePost(homePost), maxTick(maxTick)
{
    for(std::pair<int, tiger::trains::ai::Post *> mapPair : *postMap)
    {
        switch(mapPair.second->getPoint()->getPost()->getPostType())
        {
        case models::PostType::MARKET:
            artMarketMap[mapPair.first] = ArtMarket(mapPair.second);
            break;
        case models::PostType::TOWN:
            artTownMap[mapPair.first] = ArtTown(mapPair.second);
            break;
        default:
            break;
        }

    }
}

double ScoreCalc::getScore(const std::vector<int> &vec)
{
    int tick = 0;
    returned = false;
    int currProduct = 0;
    const Post* lastPost = startPost;

    for (int idx : vec)
    {
        const Post* post = (*postMap)[idx];
        for (auto point : post->getMinPath(startPost->getPoint()))
        {
            if (returned)
                break;

            if ((*postMap).count(point->getIdx()) == 0)
                continue;

            const Post* tempPost = (*postMap)[point->getIdx()];
            switch (point->getPost()->getPostType())
            {
                case models::PostType::MARKET:
                    goToMarket(lastPost, artMarketMap[tempPost->getPoint()->getIdx()], tick, currProduct);
                    lastPost = tempPost;
                    break;
                case models::PostType::TOWN:
                    goToTown(lastPost, artTownMap[tempPost->getPoint()->getIdx()], tick, currProduct);
                    lastPost = tempPost;
                    break;
                default:
                    break;
            }

        }

        if (returned)
            break;

    }

    ArtTown town(homePost);
    if (artTownMap[homePost->getPoint()->getIdx()].getPopulation() != town.getPopulation())
        return -1;
    return artTownMap[homePost->getPoint()->getIdx()].getProduct();

}

void ScoreCalc::goToMarket(const Post* post, ArtMarket artMarket, int &tick, int &products)
{

    int len = post->getMinLen(artMarket.getPost()->getPoint()); // Path to Market
    int home_len = artMarket.getPost()->getMinLen(homePost->getPoint()); // Path to Home from Market

    ArtTown &homeTown = artTownMap[homePost->getPoint()->getIdx()];
    ArtTown newTown = homeTown.getFuture(tick + len + home_len);

    if (tick + len + home_len > maxTick || newTown.getPopulation() != homeTown.getPopulation())
    {
        if (tick + len + home_len > maxTick)
            returned = true;
        goToTown(post, homeTown, tick, products);
        post = homePost;
    }

    len = post->getMinLen(artMarket.getPost()->getPoint());
    tick += len;

    ArtMarket newArtMarket = artMarket.getFuture(tick);

    products += newArtMarket.takeProduct(newArtMarket.getProduct());

    artMarketMap[newArtMarket.getPost()->getPoint()->getIdx()] = newArtMarket;
}

void ScoreCalc::goToTown(const Post* post, ArtTown artTown, int &tick, int &products)
{
    int len = post->getMinLen(artTown.getPost()->getPoint()); // Path to home
    tick += len;
    ArtTown newArtTown = artTown.getFuture(tick);
    newArtTown.addProduct(products);
    products = 0;
    artTownMap[artTown.getPost()->getPoint()->getIdx()] = newArtTown;

}
