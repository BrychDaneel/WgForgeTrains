#pragma once
#ifndef _TIGER_TRAINS_GUI_WORLD_WIDGET_H_
#define _TIGER_TRAINS_GUI_WORLD_WIDGET_H_


#include <QWidget>
#include <world/World.h>
#include <vector>
#include <QMap>


namespace tiger {
namespace trains {
namespace gui {


class QWorldWidget : public QWidget{

private:

    world::World* world;
    QMap<world::Point*, QPointF> pointCoords;

    float maxX = 0;
    float maxY = 0;

    bool graphBuilded = false;

    void buildGraph();

public:

    QWorldWidget(world::World* world);

protected:

    void paintEvent(QPaintEvent* event);

};


}
}
}


#endif
