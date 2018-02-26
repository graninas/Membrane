
#ifndef WORLD_H
#define WORLD_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

#include "membrane/membrane.h"
#include "membrane/schememanager.h"

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

    int _nextStepTime;
    membrane::TwoBraneWorld _w;
    membrane::SchemeManager _topManager;
    membrane::SchemeManager _bottomManager;

private:

    void drawBrane(QPainter *painter, bool topBrane, membrane::I canvasOffsetX, membrane::I canvasOffsetY, membrane::I viewPosX, membrane::I viewPosY);
};

#endif
