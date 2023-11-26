#include <QApplication>
#include "PowerPoint.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("PowerPoint");
    PowerPoint w;
    w.show();
    return a.exec();
}
