#pragma once


#include <QWidget>
#include <world/World.h>
#include <vector>
#include <QMap>
#include <QMouseEvent>


namespace tiger {
namespace trains {
namespace gui {


class QWorldWidget : public QWidget{

private:

    world::World* world;

    float rectHeight = 100;
    float rectWidth = 100;
    QPointF camPos = QPointF(0, 0);
    QPoint lastCursorPos = QPoint(-1, -1);

public:

    QWorldWidget(world::World* world);

    void setRectWidth(float width);
    float getRectWidth() const;

    void setRectHeight(float height);
    float getRectHeight() const;

protected:

    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

    void drawLines(QPainter* painter);
    void drawPoints(QPainter* painter);
    void drawPosts(QPainter* painter);
    void drawTrains(QPainter* painter);
    void drawTick(QPainter* painter);
    void drawScore(QPainter* painter);
    void drawGameOver(QPainter* painter);

};


}
}
}
