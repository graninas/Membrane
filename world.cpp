
#include "world.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

using namespace membrane;

World::World()
{
    m_w = createRandomWorld(100, 40, 60, 40, 60);

    setCell(m_w, 0, 0, cBottomBrane, cAlive);

    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}

void World::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
    painter->fillRect(event->rect(), background);
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);

    I cellRadius = 10;
    I canvasOffset = 0;
    I viewPosX = 450;
    I viewPosY = 500;

    for (auto i = 0; i < m_w.bottomBrane.size(); ++i)
        for (auto j = 0; j < m_w.bottomBrane[i].size(); ++j)
        {
            if (m_w.bottomBrane[i][j] == cAlive)
            {
                auto x = canvasOffset + i * cellRadius * 2 - viewPosX;
                auto y = canvasOffset + j * cellRadius * 2 - viewPosY;
                auto w = cellRadius;
                auto h = cellRadius;
                painter->drawEllipse(x, y, w, h);
            }
        }
}
