#include "m.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    M w;
    w.show();

    return a.exec();
}
