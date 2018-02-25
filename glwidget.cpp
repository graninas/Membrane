
#include "glwidget.h"
#include "world.h"

#include <QPainter>
#include <QTimer>

GLWidget::GLWidget(World *world, QWidget *parent)
    : QOpenGLWidget(parent), world(world)
{
    elapsed = 0;
    setFixedSize(1800, 1000);
    setAutoFillBackground(false);
}

void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    world->paint(&painter, event, elapsed);
    painter.end();
}
