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


public:

    QWorldWidget(world::World* world);

protected:

    void paintEvent(QPaintEvent* event);

    void drawLines(QPainter* painter);
    void drawPoints(QPainter* painter);
    void drawPosts(QPainter* painter);
    void drawTrains(QPainter* painter);
    void drawTick(QPainter* painter);

};


}
}
}


#endif
