
#ifndef WORLD_H
#define WORLD_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

#include "membrane.h"

class World
{
public:
    World();

public:
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush background;
    QBrush circleBrush;
    QBrush lineBrush;
    QFont textFont;
    QPen circlePen;
    QPen linePen;
    QPen textPen;

    int m_nextStepTime;
    membrane::TwoBraneWorld m_w;

private:

    void drawBrane(QPainter *painter, bool topBrane, membrane::I viewPosX, membrane::I viewPosY);
};

#endif
