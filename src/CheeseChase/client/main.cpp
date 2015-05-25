#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // get hostname
    // QString host = QInputDialog::getText(NULL, "Host", "Enter a hostname");

    // pass hostname to network manager

    // setup mainwindow and show
    MainWindow mainwindow;
    mainwindow.show();

    return app.exec();
}
