#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);

    blackpen.setWidth(6);


    // sceneDynamic->addEllipse(10, 10, 100, 100, blackpen, redBrush);
    // sceneDynamic->addRect(10, 10, 50, 50, blackpen, blueBrush);

    //rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonUp_clicked()
{
    //ui->graphicsView->rotate(-10);
}

void MainWindow::on_pushButtonLeft_clicked()
{
    //ui->graphicsView->rotate(10);
}

void MainWindow::on_pushButtonDown_clicked()
{
    // TODO
}

void MainWindow::on_pushButtonRight_clicked()
{
    // TODO
}
