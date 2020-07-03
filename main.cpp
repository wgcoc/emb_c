#include <QCoreApplication>
#include "Business.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Business::get_instance()->start();
    return a.exec();
}

