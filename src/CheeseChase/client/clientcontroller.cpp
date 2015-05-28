#include "mainwindow.h"
#include "gamemodel.h"
#include "clientcontroller.h"
#include "Level.hpp"
#include <Wall.h>
#include <Floor.h>
#include <QApplication>
#include <QInputDialog>

cheesechase::ClientController::ClientController() :
    _gamemodel(new GameModel()),
    _view(new MainWindow()),
    _timer(new QTimer(_view.get()))
{

}

cheesechase::ClientController::~ClientController()
{
}

void cheesechase::ClientController::run()
{
    // get hostname
    QString host = QInputDialog::getText(_view.get(), "Host", "Enter a hostname");
    //if(host.isEmpty()) {

    //}

    // pass hostname to network manager and connect to server
    // TODO

    // TODO DELETE!!
    serverSetupMock();

    // connect the model to the view
    _view->setModel(_gamemodel);

    // show the view
    _view->show();

    // setup the render timer (calls render each x milliseconds)
    QObject::connect(_timer.get(), SIGNAL(timeout()), _view.get(), SLOT(render()));
    _timer->start(250);
}

// TODO DELETE!!
void cheesechase::ClientController::serverSetupMock()
{
    // create a level
    std::vector<std::vector<Tile *>> levelData {
    {new Floor(),new Floor(),new Floor(),new Floor(),new Wall(),new Floor(),new Floor(),new Floor()},
    {new Floor(),new Floor(),new Wall(),new Floor(),new Wall(),new Floor(),new Wall(),new Wall()},
    {new Floor(),new Floor(),new Wall(),new Floor(),new Wall(),new Floor(),new Floor(),new Floor()},
    {new Wall(),new Floor(),new Floor(),new Floor(),new Floor(),new Wall(),new Floor(),new Wall(),new Wall()},
    {new Wall(),new Floor(),new Floor(),new Wall(),new Floor(),new Wall(),new Floor(),new Floor()},
    {new Floor(),new Wall(),new Wall(),new Floor(),new Floor(),new Floor(),new Wall(),new Floor(),new Wall()},
    {new Wall(),new Floor(),new Wall(),new Floor(),new Floor(),new Floor(),new Wall(),new Wall()},
    {new Wall(),new Wall(),new Wall(),new Floor(),new Floor(),new Floor(),new Floor(),new Wall()},
    {new Wall(),new Floor(),new Floor(),new Floor(),new Wall(),new Wall(),new Wall(),new Wall()},
    {new Floor(),new Floor(),new Wall(),new Floor(),new Floor(),new Floor(),new Floor(),new Floor()}
    };

    std::shared_ptr<Level> level(new Level(levelData));

    _gamemodel->setLevel(level);
}
