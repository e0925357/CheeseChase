#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QtCore>
#include <QtGui>
#include <memory>

namespace cheesechase {
    class MainWindow;
    class GameModel;

    class ClientController
    {
    public:
        ClientController();
        ~ClientController();
        void run();

    private:
        // TODO DELETE!!
        void serverSetupMock();

        std::unique_ptr<QTimer> _timer;
        std::unique_ptr<MainWindow> _view;
        std::shared_ptr<GameModel> _gamemodel;
        std::shared_ptr<QStandardItemModel> _playermodel;
    };
}

#endif // CLIENTCONTROLLER_H
