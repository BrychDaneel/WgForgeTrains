#include <gui/QWorldWidget.h>


#include <utils/GraphPlaner.h>
#include <QMap>
#include <vector>
#include <QPainter>
#include <QTimer>
#include <world/Market.h>
#include <world/Town.h>
#include <sstream>


namespace tiger {
namespace trains {
namespace gui {


QWorldWidget::QWorldWidget(world::World* world) : world(world){
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(500);
}


void QWorldWidget::buildGraph(){

    int len = 0;
    QMap<world::Point*, int> pointToInd;
    std::vector<std::vector<std::pair<int, float> > > graph;
    for (world::Point* point : world->getPointList()){
        pointToInd[point] = len++;
        std::vector<std::pair<int, float> > v;
        graph.push_back(v);
    }

    for (tiger::trains::world::Line* line : world->getLineList()){
        int si = pointToInd[line->getStartPont()];
        int ei = pointToInd[line->getEndPont()];
        graph[si].push_back(std::pair<int, float> (ei, line->getLenght()));
        graph[ei].push_back(std::pair<int, float> (si, line->getLenght()));
    }

    std::vector<std::pair<float, float> > coords = tiger::trains::utils::GraphPlaner::planeGraph(graph, time(0));

    for (int i=0; i<len; i++){
        std::pair<float, float> c = coords[i];

        if (c.first * 10 > maxX)
            maxX = c.first  * 10;
        if (c.second  * 10 > maxY)
            maxY = c.second  * 10;
        pointCoords[world->getPointList()[i]] = QPointF(c.first, c.second) * 10;
    }

}


void QWorldWidget::drawLines(QPainter* painter){
    painter->setPen(QPen(Qt::blue, 0.5));
    for (world::Line* line : world->getLineList()){
        QLineF qline(pointCoords[line->getStartPont()], pointCoords[line->getEndPont()]);
        painter->drawLine(qline);
    }
}


void QWorldWidget::drawPoints(QPainter* painter){
    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);

    painter->setPen(QPen(Qt::white, 0));
    painter->setBrush(Qt::white);
    for (world::Point* point : world->getPointList()){
        QPointF ppoint = pointCoords[point];
        painter->drawEllipse(ppoint, 1, 1);
        QRectF textRect(ppoint - QPoint(2, 1), ppoint - QPoint(1, 0));
        painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(point->getIdx()));
    }
}


void QWorldWidget::drawPosts(QPainter* painter){

    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);
    painter->setPen(QPen(Qt::yellow, 0));
    for (world::IPost* post : world->getPostList()){

            switch (post->getPostType()) {
            case models::PostType::TOWN:
                painter->setPen(QPen(Qt::yellow, 0));
                painter->setBrush(Qt::yellow);
                break;
            case models::PostType::MARKET:
                painter->setPen(QPen(Qt::green, 0));
                painter->setBrush(Qt::green);
                break;
            default:
                painter->setPen(QPen(Qt::yellow, 0));
                break;
            }

            QPointF ppoint = pointCoords[post->getPoint()];
            QRectF textRect(ppoint - QPoint(5, 2), ppoint - QPoint(-5, 1));
            QString name = QString::fromStdString(post->getName());

            painter->drawEllipse(ppoint, 1, 1);

            painter->drawText(textRect, Qt::AlignCenter, name);

            if (post->getPostType() == models::PostType::MARKET){
                QRectF prodRect(ppoint + QPoint(-5, 1), ppoint + QPoint(5, 2));
                world::Market* market = (world::Market*)post;
                QString productText = QString("product: %1").arg(market->getProduct());
                painter->drawText(prodRect, Qt::AlignCenter, productText);
            }

            if (post->getPostType() == models::PostType::TOWN){
                world::Town* town = (world::Town*)post;

                QRectF prodRect(ppoint + QPoint(-5, 1), ppoint + QPoint(5, 2));
                QString productText = QString("product: %1").arg(town->getProduct());
                painter->drawText(prodRect, Qt::AlignCenter, productText);

                QRectF popRect(ppoint + QPoint(-5, 2), ppoint + QPoint(5, 3));
                QString popText = QString("populat: %1").arg(town->getPopulation());
                painter->drawText(popRect, Qt::AlignCenter, popText);
            }
    }
}


void QWorldWidget::drawTrains(QPainter* painter){
    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::red, 0));
    for (world::Train* train : world->getTrainList())
        if (train->getLine() != nullptr){
            world::Line* line = train->getLine();

            QPointF lpoint1 = pointCoords[line->getStartPont()];
            QPointF lpoint2 = pointCoords[line->getEndPont()];

            float progress = train->getPosition() / (float) line->getLenght();
            QPointF trainPoint;
            trainPoint.rx() = lpoint2.x() * progress + lpoint1.x() * (1 - progress);
            trainPoint.ry() = lpoint2.y() * progress + lpoint1.y() * (1 - progress);
            painter->drawEllipse(trainPoint, 0.7, 0.7);


        }
}


void QWorldWidget::paintEvent(QPaintEvent* event){

    if (!graphBuilded){
        if (!world->isInitialized())
            return;
        else{
            buildGraph();
            graphBuilded = true;
        }
    }

    QPainter painter;

    painter.begin(this);

    painter.setPen(QPen(Qt::black, 0));
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

    painter.scale( width() / maxX / 1.2, height() / maxY / 1.2);
    painter.translate(maxX * 0.1, maxY * 0.1);

    drawLines(&painter);
    drawPoints(&painter);
    drawPosts(&painter);
    drawTrains(&painter);

    painter.end();

}


}
}
}
