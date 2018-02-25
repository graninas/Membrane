#include "window.h"

#include <QApplication>
#include <QSurfaceFormat>

#include "membrane.h"

using namespace membrane;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Window window;
    window.show();
    return app.exec();
}
