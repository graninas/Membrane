
#include "world.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

using namespace membrane;

const int cStepDelay = 100;

World::World()
{
    m_nextStepTime = 0;
    m_w = createRandomWorld(100, 40, 60, 40, 60);

    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    lineBrush = QBrush(QColor(0,171,235));
    linePen = QPen(QColor(0,171,235));
    linePen.setWidth(1);

    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}

void drawVerticalLine(QPainter *painter, int x, QBrush &brush, QPen &pen)
{
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawLine(x, 0, x, 5000); // TODO: magic const
}

void drawHorizontalLine(QPainter *painter, int y, QBrush &brush, QPen &pen)
{
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawLine(0, y, 5000, y); // TODO: magic const
}

void World::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
//    if (elapsed < m_nextStepTime)
//        return;

    m_nextStepTime = elapsed + cStepDelay;

    m_w = step(m_w);

    painter->fillRect(event->rect(), background);
//    drawBrane(painter, cBottomBrane, 450, 500);
    drawBrane(painter, cTopBrane, 450, 500);
}

void World::drawBrane(QPainter *painter, bool topBrane, I viewPosX, I viewPosY)
{
    Area& brane = topBrane ? m_w.topBrane : m_w.bottomBrane;

    I cellRadius = 10;
    I canvasOffset = 0;

    for (auto i = 0; i < brane.size(); ++i)
    {
        drawVerticalLine(painter, canvasOffset + i * cellRadius * 2 - cellRadius / 2 - viewPosX, lineBrush, linePen);
        for (auto j = 0; j < brane[i].size(); ++j)
        {
            drawHorizontalLine(painter, canvasOffset + j * cellRadius * 2 - cellRadius / 2 - viewPosY, lineBrush, linePen);

            if (brane[i][j] == cAlive)
            {
                auto x = canvasOffset + i * cellRadius * 2 - viewPosX;
                auto y = canvasOffset + j * cellRadius * 2 - viewPosY;
                auto w = cellRadius;
                auto h = cellRadius;

                painter->setBrush(circleBrush);
                painter->setPen(circlePen);
                painter->drawEllipse(x, y, w, h);
            }
        }
    }
}
