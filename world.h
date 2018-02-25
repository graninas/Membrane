
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
    QFont textFont;
    QPen circlePen;
    QPen textPen;

    membrane::TwoBraneWorld m_w;
};

#endif
