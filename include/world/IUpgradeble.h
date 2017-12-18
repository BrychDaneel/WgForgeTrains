#pragma once


namespace tiger{
namespace trains{
namespace world{


struct IUpgradeble{

    virtual ~IUpgradeble(){}
    virtual int getLevel() const = 0;
    virtual int getNextLevelPrice() const = 0;
    virtual bool upgrade() const = 0;

};


}
}
}

