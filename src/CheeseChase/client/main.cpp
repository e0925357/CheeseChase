#include "clientcontroller.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    // setup
    QApplication app(argc, argv);

    cheesechase::ClientController controller;
    controller.run();

    return app.exec();
}
