#include "gamemodel.h"
#include "mainwindow.h"
#include "Level.hpp"
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
    _wallPixmap(QPixmap(":/level/wall.jpg")),
    _floorPixmap(QPixmap(":/level/floor.jpg")),
    _mousePixmap(QPixmap(":/level/mouse.png"))
{
    _ui->setupUi(this);
    _ui->graphicsView->setScene(_scene.get());
    _ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    _scene->addText("work in progress here");
}

cheesechase::MainWindow::~MainWindow()
{
}

void cheesechase::MainWindow::setModel(std::shared_ptr<cheesechase::GameModel> gamemodel)
{
    _gamemodel = std::move(gamemodel);
}

void cheesechase::MainWindow::render()
{
    _scene->clear();

    // 1. render level
    auto level = _gamemodel->getLevel();
    unsigned int cols = level->getCols();
    unsigned int rows = level->getRows();

    for(unsigned int x = 0; x < cols; ++x)
    {
        for(unsigned int y = 0; y < rows; ++y)
        {
            Tile *tile = level->getTile(Vec2i(x,y));

            // set the pixmap image corresponding to the type
            QGraphicsPixmapItem *item;
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
        QGraphicsPixmapItem *item = _scene->addPixmap(mousePixmap);

        // position the mouse
        QTransform t;

        t.translate(_floorPixmap.width()/2.0, _floorPixmap.height()/2.0);
        t.translate(_floorPixmap.width()*pos[0], _floorPixmap.height()*pos[1]);
        t.rotate(90 * (qrand() % 4));
        t.translate(-_floorPixmap.width()/2.0, -_floorPixmap.height()/2.0);

        item->setTransform(t);
        //item->setOffset(_floorPixmap.width()*pos[0], _floorPixmap.height()*pos[1]);

        // TODO rotate in the direction the mouse is moving
        //item->setTransformOriginPoint(item->pos());
        //item->setRotation(90 * (qrand() % 4));

        // smoothing? fo' shizzle my nizzle
        item->setTransformationMode(Qt::SmoothTransformation);

        ++mouseIdx;
    }


    // 3. render wind

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
