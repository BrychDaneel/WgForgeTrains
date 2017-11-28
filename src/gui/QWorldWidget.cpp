#include <gui/QWorldWidget.h>


#include <utils/GraphPlaner.h>
#include <QMap>
#include <vector>
#include <QPainter>
#include <QTimer>

namespace tiger {
namespace trains {
namespace gui {


QWorldWidget::QWorldWidget(world::World * world) : world(world){
    QTimer * timer = new QTimer(this);
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

    for (tiger::trains::world::Line * line : world->getLineList()){
                int si = pointToInd[line->getStartPont()];
                int ei = pointToInd[line->getEndPont()];
                graph[si].push_back(std::pair<int, float> (ei, line->getLenght()));
                graph[ei].push_back(std::pair<int, float> (si, line->getLenght()));
            }

    std::vector<std::pair<float, float> > coords = tiger::trains::utils::GraphPlaner::planeGraph(graph, time(0));

    for (int i=0; i<len; i++){
        std::pair<float, float> c = coords[i];

        if (c.first > maxX)
            maxX = c.first;
        if (c.second > maxY)
            maxY = c.second;
        pointCoords[world->getPointList()[i]] = QPointF(c.first, c.second);
    }

}

void QWorldWidget::paintEvent(QPaintEvent * event){

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

    painter.setPen(QPen(Qt::blue, 0.3));
    for (world::Line* line : world->getLineList()){
        QLineF qline(pointCoords[line->getStartPont()], pointCoords[line->getEndPont()]);
        painter.drawLine(qline);
    }

    painter.setPen(QPen(Qt::white, 0.3));
    painter.setBrush(Qt::white);
    for (world::Point* point : world->getPointList())
        painter.drawEllipse(pointCoords[point], 0.5, 0.5);

    painter.setBrush(Qt::red);
    painter.setPen(QPen(Qt::red, 0.3));
    for (world::Train* train : world->getTrainList())
        if (train->getLine() != nullptr){
            world::Line* line = train->getLine();

            QPointF lpoint1 = pointCoords[line->getStartPont()];
            QPointF lpoint2 = pointCoords[line->getEndPont()];

            float progress = train->getPosition() / (float) line->getLenght();
            QPointF trainPoint;
            trainPoint.rx() = lpoint2.x() * progress + lpoint1.x() * (1 - progress);
            trainPoint.ry() = lpoint2.y() * progress + lpoint1.y() * (1 - progress);
            painter.drawEllipse(trainPoint, 0.3, 0.3);


        }

    painter.end();

}


}
}
}

