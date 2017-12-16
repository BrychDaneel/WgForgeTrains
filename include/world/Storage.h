#pragma once


#include <world/BasePost.h>


namespace tiger{
namespace trains{
namespace world{


class Storage : public BasePost{

private:

    int armor;
    int replenishment;
    int armorCapacity;

public:

    Storage();

    Storage(const models::PostModel& model, World* world);
    void update(const models::PostModel& model);

    int getArmor() const;
    int getReplenishment() const;
    int getArmorCapacity() const;

    int predictArmor(int delta, int visitTime=-1) const;

};


}
}
}
