#include "world.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

#include "membrane/patterns.h"
#include "membrane/logic.h"

using namespace membrane;

const I cStepDelay = 100;
const I cCellRadius = 4;
const I cCellDiameter = cCellRadius * 2;
const I cCellHalfRadius = cCellRadius / 2;

World::World()
{
    _nextStepTime = 0;
    _w = createWorld(100);

    Schemes bottomSchemes =
    { Scheme { h3Line(), pointBlueprint(), 1, 0 }
    };

    _bottomManager = SchemeManager();
    _bottomManager.setSchemes(bottomSchemes);

    _topManager = SchemeManager();

    fill2SideBlocks(_w.bottomBrane, 10);
    fill2SideBlocks(_w.topBrane, 10);
    fillRandomUnsafe(_w.bottomBrane, 40, 60, 40, 60, 4);

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

void drawVerticalLine(QPainter *painter, int x, int minY, int maxY, QBrush &brush, QPen &pen)
{
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawLine(x, minY, x, maxY);
}

void drawHorizontalLine(QPainter *painter, int y, int minX, int maxX, QBrush &brush, QPen &pen)
{
    painter->setBrush(brush);
    painter->setPen(pen);
    painter->drawLine(minX, y, maxX, y);
}

void World::paint(QPainter *painter, QPaintEvent *event, int elapsed)
{
    _nextStepTime = elapsed + cStepDelay;

    _w = step(_w, _bottomManager, _topManager);

    painter->fillRect(event->rect(), background);
    drawBrane(painter, cBottomBrane, 0, 0, 0, 0);
    drawBrane(painter, cTopBrane, _w.areaDimension * cCellDiameter + 20, 0, 0, 0);
}

void World::drawBrane(QPainter *painter, bool topBrane, I canvasOffsetX, I canvasOffsetY, I viewPosX, I viewPosY)
{
    Area& brane = topBrane ? _w.topBrane : _w.bottomBrane;

    I minX = canvasOffsetX - cCellHalfRadius - viewPosX;
    I maxX = canvasOffsetX + brane.size() * cCellDiameter - cCellHalfRadius - viewPosX;

    I minY = canvasOffsetY - cCellHalfRadius - viewPosY;
    I maxY = canvasOffsetY + brane.size() * cCellDiameter - cCellHalfRadius - viewPosY;

    for (I i = 0; i < brane.size(); ++i)
    {
        auto gridX = canvasOffsetX + i * cCellDiameter - cCellHalfRadius - viewPosX;
        drawVerticalLine(painter, gridX, minY, maxY, lineBrush, linePen);

        for (I j = 0; j < brane[i].size(); ++j)
        {
            auto gridY = canvasOffsetY + j * cCellDiameter - cCellHalfRadius - viewPosY;
            drawHorizontalLine(painter, gridY, minX, maxX, lineBrush, linePen);

            if (brane[i][j] == cAlive)
            {
                auto x = canvasOffsetX + i * cCellDiameter - viewPosX;
                auto y = canvasOffsetY + j * cCellDiameter - viewPosY;

                painter->setBrush(circleBrush);
                painter->setPen(circlePen);
                painter->drawEllipse(x, y, cCellRadius, cCellRadius);
            }
        }
    }
}
