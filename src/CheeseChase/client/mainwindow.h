#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>

namespace Ui {
class MainWindow;
}

namespace cheesechase {
    class GameModel;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void setGamemodel(std::shared_ptr<GameModel> gamemodel);
        void setPlayermodel(std::shared_ptr<QStandardItemModel> playermodel);

    public slots:
        void render();

    private slots:
        void on_pushButtonUp_clicked();

        void on_pushButtonLeft_clicked();

        void on_pushButtonDown_clicked();

        void on_pushButtonRight_clicked();

    private:
        std::unique_ptr<Ui::MainWindow> _ui;
        std::unique_ptr<QGraphicsScene> _scene;
        std::shared_ptr<GameModel> _gamemodel;
        std::shared_ptr<QStandardItemModel> _playermodel;

        QPixmap _wallPixmap;
        QPixmap _floorPixmap;
        QPixmap _mousePixmap;
        QPixmap _cheesePixmap;
    };
}

#endif // MAINWINDOW_H
