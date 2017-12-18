#include <gui/QWorldWidget.h>


#include <QMap>
#include <vector>
#include <QPainter>
#include <QTimer>
#include <world/Market.h>
#include <world/Storage.h>
#include <world/Town.h>
#include <sstream>


namespace tiger
{
namespace trains
{
namespace gui
{


QWorldWidget::QWorldWidget(world::World* world) : world(world)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(100);
    setMouseTracking(true);
}


void QWorldWidget::drawLines(QPainter* painter)
{
    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);

    painter->setPen(QPen(Qt::blue, 0.5));
    for (world::Line* line : world->getLineList()){
        QPointF start(line->getStartPont()->getX(), line->getStartPont()->getY());
        QPointF end(line->getEndPont()->getX(), line->getEndPont()->getY());
        QLineF qline(start, end);
        painter->drawLine(qline);

        QPointF middle = (start + end) / 2;
        QRectF textRect(middle - QPoint(1, 2), middle - QPoint(-1, 1));
        painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(line->getLenght()));
    }
}


void QWorldWidget::drawPoints(QPainter* painter)
{
    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);

    painter->setPen(QPen(Qt::white, 0));
    painter->setBrush(Qt::white);
    for (world::Point* point : world->getPointList()){
        QPointF ppoint(point->getX(), point->getY());
        painter->drawEllipse(ppoint, 1, 1);
        QRectF textRect(ppoint - QPoint(2, 1), ppoint - QPoint(1, 0));
        painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(point->getIdx()));
    }
}


void QWorldWidget::drawPosts(QPainter* painter)
{

    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);
    painter->setPen(QPen(Qt::yellow, 0));
    for (world::IPost* post : world->getPostList()){

            switch (post->getPostType()) {
            case models::PostType::TOWN:
                painter->setPen(QPen(Qt::green, 0));
                painter->setBrush(Qt::green);
                break;
            case models::PostType::STORAGE:
                painter->setPen(QPen(Qt::yellow, 0));
                painter->setBrush(Qt::yellow);
                break;
            case models::PostType::MARKET:
                painter->setPen(QPen(Qt::magenta, 0));
                painter->setBrush(Qt::magenta);
                break;
            default:
                painter->setPen(QPen(Qt::gray, 0));
                painter->setBrush(Qt::gray);
                break;
            }

            QPointF ppoint(post->getPoint()->getX(), post->getPoint()->getY());
            QRectF textRect(ppoint - QPoint(5, 2), ppoint - QPoint(-5, 1));
            QString name = QString::fromStdString(post->getName());

            painter->drawEllipse(ppoint, 1, 1);

            painter->drawText(textRect, Qt::AlignCenter, name);

            if (post->getPostType() == models::PostType::MARKET){
                QRectF prodRect(ppoint + QPoint(-5, 1), ppoint + QPoint(5, 2));
                world::Market* market = (world::Market*)post;
                QString productText = QString("%1/%2").arg(market->getProduct()).arg(market->getProductCapacity());
                painter->drawText(prodRect, Qt::AlignCenter, productText);
            }

            if (post->getPostType() == models::PostType::STORAGE){
                QRectF prodRect(ppoint + QPoint(-5, 1), ppoint + QPoint(5, 2));
                world::Storage* storage = static_cast<world::Storage*>(post);
                QString productText = QString("%1/%2").arg(storage->getArmor()).arg(storage->getArmorCapacity());
                painter->drawText(prodRect, Qt::AlignCenter, productText);
            }

            if (post->getPostType() == models::PostType::TOWN){
                world::Town* town = (world::Town*)post;

                QRectF prodRect(ppoint + QPoint(-5, 1), ppoint + QPoint(5, 2));
                QString productText = QString("product: %1").arg(town->getProduct());
                painter->drawText(prodRect, Qt::AlignCenter, productText);

                QRectF armorRect(ppoint + QPoint(-5, 2), ppoint + QPoint(5, 3));
                QString armorText = QString("armor: %1").arg(town->getArrmor());
                painter->drawText(armorRect, Qt::AlignCenter, armorText);

                QRectF popRect(ppoint + QPoint(-5, 3), ppoint + QPoint(5, 4));
                QString popText = QString("populat: %1").arg(town->getPopulation());
                painter->drawText(popRect, Qt::AlignCenter, popText);
            }
    }
}


void QWorldWidget::drawTrains(QPainter* painter)
{
    QFont font = painter->font();
    font.setPixelSize(1);
    painter->setFont(font);

    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::red, 0));
    for (world::Train* train : world->getTrainList())
        if (train->getLine() != nullptr){
            world::Line* line = train->getLine();

            QPointF lpoint1(line->getStartPont()->getX(), line->getStartPont()->getY());
            QPointF lpoint2(line->getEndPont()->getX(), line->getEndPont()->getY());

            float progress = train->getPosition() / (float) line->getLenght();
            QPointF trainPoint;
            trainPoint.rx() = lpoint2.x() * progress + lpoint1.x() * (1 - progress);
            trainPoint.ry() = lpoint2.y() * progress + lpoint1.y() * (1 - progress);
            painter->drawEllipse(trainPoint, 0.7, 0.7);


            QRectF prodRect(trainPoint + QPoint(-5, 1), trainPoint  + QPoint(5, 2));
            QString productText = QString("%1/%2").arg(train->getGoods()).arg(train->getGoodsCapacity());
            painter->drawText(prodRect, Qt::AlignCenter, productText);
        }
}


void QWorldWidget::drawTick(QPainter* painter)
{
    QFont font = painter->font();
    font.setPixelSize(width() / 20);
    painter->setFont(font);
    painter->setPen(QPen(Qt::white, 0));

    QRectF textRect(0, 0, width() / 7.0, height() / 10.0);
    painter->drawText(textRect, Qt::AlignCenter, QString("%1").arg(world->getTickNum()));
}


void QWorldWidget::drawScore(QPainter* painter)
{
    QFont font = painter->font();
    font.setPixelSize(width() / 40);
    painter->setFont(font);
    painter->setPen(QPen(Qt::yellow, 0));

    QRectF textRect(width() / 7.0, 0, width(), height() / 10.0);

    QString text;
    for (world::Player* player : world->getPlayerList())
        if (text != "")
            text += "     ";
        else
            text += QString("%1: %2").arg(player->getName().c_str()).arg(player->getScore());
    painter->drawText(textRect, Qt::AlignCenter, text);
}


void QWorldWidget::drawGameOver(QPainter* painter){
    QFont font = painter->font();
    font.setPixelSize(width() / 10);
    painter->setFont(font);
    painter->setPen(QPen(Qt::red, 0));

    QRectF textRect(0, 0, width(), height());
    painter->drawText(textRect, Qt::AlignCenter, "GAME OVER!");
}


void QWorldWidget::paintEvent(QPaintEvent* event)
{
    if (world->getWidth() == 0 || world->getHeight() == 0)
        return;

    QPainter painter;

    painter.begin(this);

    painter.setPen(QPen(Qt::black, 0));
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, width(), height());

    drawTick(&painter);
    drawScore(&painter);
    if (world->isGameOver())
        drawGameOver(&painter);

    painter.scale( width() / 1.2 / rectWidth, height() / 1.2 / rectWidth);
    painter.translate(world->getWidth() * 0.1, world->getHeight() * 0.1);

    painter.translate(-camPos);

    drawLines(&painter);
    drawPoints(&painter);
    drawPosts(&painter);
    drawTrains(&painter);

    painter.end();

}


void QWorldWidget::setRectHeight(float height)
{
    rectHeight = height;
}


float QWorldWidget::getRectHeight() const
{
    return rectHeight;
}


void QWorldWidget::setRectWidth(float width)
{
    rectWidth = width;
}


float QWorldWidget::getRectWidth() const{
    return rectWidth;
}


void QWorldWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (lastCursorPos.x() == -1){
        lastCursorPos = event->pos();
        return;
    }

    if (event->buttons() && Qt::LeftButton != 0)
        camPos += (lastCursorPos - event->pos()) / 20;

    if (camPos.x() < 0)
        camPos.rx() = 0;

    if (camPos.y() < 0)
        camPos.ry() = 0;

    if (camPos.x() > world->getWidth())
        camPos.rx() = world->getWidth();

    if (camPos.y() > world->getHeight())
        camPos.ry() = world->getHeight();

    lastCursorPos = event->pos();
}


}
}
}
