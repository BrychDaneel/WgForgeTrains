#pragma once
#ifndef _TIGER_TRAINS_GUI_TICKER_H_
#define _TIGER_TRAINS_GUI_TICKER_H_

#include <client/TCPTrainClient.h>
#include <world/World.h>
#include <gui/WorldWidget.h>

using tiger::trains::world::World;
using tiger::trains::models::PlayerModel;
using tiger::trains::client::TCPTrainClient;
using tiger::trains::gui::WorldWidget;
using tiger::trains::models::DynamicMap;
using tiger::trains::models::StaticMap;

namespace tiger {
namespace trains {
namespace gui {

    class Ticker : public QObject{
        Q_OBJECT
    private:
        World * world;
        TCPTrainClient * trainClient;
        WorldWidget * worldWidget;

    public:
        Ticker(World* world, TCPTrainClient * trainClient, WorldWidget * worldWidget, QObject * pobj = 0) : QObject(pobj){
            this->world = world;
            this->trainClient = trainClient;
            this->worldWidget = worldWidget;
        }

    public slots:
        void tick(){
            std::shared_ptr<const DynamicMap> dynamicMap = trainClient->getDynamicMap();
            world->update(*dynamicMap);
            worldWidget->repaint();
        }
    };

}
}
}

#endif
