#include "readcloudpoint.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    readCloudPoint w;
    w.show();

    return a.exec();
}
