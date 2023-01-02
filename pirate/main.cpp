#include "ckernel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ckernel::getInstance();
    return a.exec();
}
