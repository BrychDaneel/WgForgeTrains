#pragma once


#include <models/PostType.h>
#include <models/EventModel.h>
#include <string>
#include <vector>


using std::string;


namespace tiger
{
namespace trains
{
namespace models
{


class PostModel
{
private:

    int idx = 0;
    PostType type = PostType::UNKNOWN;
    int armor = 0;
    string name;
    int population = 0;
    int product = 0;
    int replenishment;
    int productCapacity;

    int armorCapacity;
    int nextLevelPrice;
    int populationCapacity;
    int level;

    std::vector<EventModel> eventList;

public:

    PostModel();
    PostModel(const int idx, const PostType type, const int armor, const string name,
              const int population, const int product, const int replenishment, const int productCapacity,
              const int armorCapacity, const int nextLevelPrice, const int populationCapacity, const int level);

    int getIdx() const;
    PostType getType() const;
    int getArmor() const;
    const string &getName() const;
    int getPopulation() const;
    int getProduct() const;
    int getReplenishment() const;
    int getProductCapacity() const;
    int getLevel() const;

    int getArmorCapacity() const;
    int getNextLevelPrice() const;
    int getPopulationCapacity() const;

    void setIdx(const int idx);
    void setType(const PostType type);
    void setArmor(const int armor);
    void setName(const string name);
    void setPopulation(const int population);
    void setProduct(const int product);
    void setReplenishment(const int replenishment);
    void setProductCapacity(const int productCapacity);

    void setArmorCapacity(const int armorCapacity);
    void setNextLevelPrice(const int nextLevelPrice);
    void setPopulationCapacity(const int populationCapacity);
    void setLevel(const int level);

    void addEvent(const EventModel &event);
    void clearEventList();
    const std::vector<EventModel> &getEventList() const;
};


}
}
}
