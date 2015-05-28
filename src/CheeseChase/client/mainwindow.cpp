#include "gamemodel.h"
#include "mainwindow.h"
#include "Tile.hpp"
#include "Wall.h"
#include "Floor.h"
#include "Vec2i.hpp"
#include "ui_mainwindow.h"

#include <iostream>

cheesechase::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _scene(new QGraphicsScene(this)),
    _gamemodel(nullptr),
    _playermodel(nullptr),
    _wallPixmap(QPixmap(":/level/wall.jpg")),
    _floorPixmap(QPixmap(":/level/floor.jpg")),
    _mousePixmap(QPixmap(":/level/mouse.png")),
    _cheesePixmap(QPixmap(":/level/cheese.png"))
{
    _ui->setupUi(this);
    _ui->graphicsView->setScene(_scene.get());
    _ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    _scene->addText("work in progress here");
}

cheesechase::MainWindow::~MainWindow()
{
}

void cheesechase::MainWindow::setGamemodel(std::shared_ptr<cheesechase::GameModel> gamemodel)
{
    _gamemodel = std::move(gamemodel);
}

void cheesechase::MainWindow::setPlayermodel(std::shared_ptr<QStandardItemModel> playermodel)
{
    _playermodel = std::move(playermodel);
    _ui->listView->setModel(_playermodel.get());
}


void cheesechase::MainWindow::render()
{
    _scene->clear();
    QGraphicsPixmapItem *item;

    // 1. render level
    unsigned int cols = _gamemodel->getLevelCols();
    unsigned int rows = _gamemodel->getLevelRows();

    for(unsigned int x = 0; x < cols; ++x)
    {
        for(unsigned int y = 0; y < rows; ++y)
        {
            Tile *tile = _gamemodel->getLevelTile(Vec2i(x,y));

            // set the pixmap image corresponding to the type
            if(tile->getTileType() == TileType::FLOOR)
                item = _scene->addPixmap(_floorPixmap);
            else
                item = _scene->addPixmap(_wallPixmap);

            // position the pixmap item
            item->setOffset(_floorPixmap.width()*x, _floorPixmap.height()*y);
            item->setTransformationMode(Qt::SmoothTransformation);
        }
    }

    // 2. render mice
    auto micePositions = _gamemodel->getMicePositions();
    unsigned int mouseIdx = 0;
    for( auto pos : micePositions)
    {
        QPixmap mousePixmap(_mousePixmap);;

        // colorize the mouse
        QColor color;
        color.setHsvF(double(mouseIdx)/double(micePositions.size()),1.0,1.0,0.5);

        QPainter painter(&mousePixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(mousePixmap.rect(), color);
        painter.end();

        // add mouse to the scene
        item = _scene->addPixmap(mousePixmap);

        // position the mouse
        QTransform t;

        t.translate(_floorPixmap.width()/2.0, _floorPixmap.height()/2.0);
        t.translate(_floorPixmap.width()*pos[0], _floorPixmap.height()*pos[1]);
        t.rotate(90 * (qrand() % 4));
        t.translate(-_floorPixmap.width()/2.0, -_floorPixmap.height()/2.0);

        item->setTransform(t);

        // smoothing? fo' shizzle my nizzle
        item->setTransformationMode(Qt::SmoothTransformation);

        ++mouseIdx;
    }

    // 3. render cheese & virtual cheese
    Vec2i cheesePosition = _gamemodel->getCheesePosition();
    Vec2d virtualCheesePosition = _gamemodel->getVirtualCheesePosition();

    QPixmap virtualCheesePixmap(_cheesePixmap);
    QPainter painter(&virtualCheesePixmap);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.fillRect(virtualCheesePixmap.rect(), QColor(255.0,255.0,255.0,120.0));
    painter.end();

    item = _scene->addPixmap(_cheesePixmap);
    item->setOffset(_floorPixmap.width()*cheesePosition.getX(), _floorPixmap.height()*cheesePosition.getY());
    item->setTransformationMode(Qt::SmoothTransformation);

    item = _scene->addPixmap(virtualCheesePixmap);
    item->setOffset(_floorPixmap.width()*virtualCheesePosition[0], _floorPixmap.height()*virtualCheesePosition[1]);
    item->setTransformationMode(Qt::SmoothTransformation);

    // 4. render wind

    // center all
    _ui->graphicsView->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
}

void cheesechase::MainWindow::on_pushButtonUp_clicked()
{
    std::cout << "up" << std::endl;
}

void cheesechase::MainWindow::on_pushButtonLeft_clicked()
{
    std::cout << "left" << std::endl;
}

void cheesechase::MainWindow::on_pushButtonDown_clicked()
{
    std::cout << "down" << std::endl;
}

void cheesechase::MainWindow::on_pushButtonRight_clicked()
{
    std::cout << "right" << std::endl;
}
