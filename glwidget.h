
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

class World;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(World *world, QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    World *world;
    int elapsed;
};

#endif
