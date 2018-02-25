#ifndef WINDOW_H
#define WINDOW_H

#include "world.h"

#include <QWidget>

#include "membrane.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    World world;
};

#endif
