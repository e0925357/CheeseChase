#ifndef BOOSTSERVERNETWORKADAPTER_H
#define BOOSTSERVERNETWORKADAPTER_H

#include <thread>
#include <vector>
#include <boost/asio.hpp>

#include "servernetworkadapter.h"

class BoostServerNetworkAdapter : public ServerNetworkAdapter
{
private:
    bool running;

    // Networking
    boost::asio::io_service &ioService;
    boost::asio::ip::tcp::acceptor tcpAcceptor;
    std::vector<boost::asio::ip::tcp::socket*> sockets;

    // Threading
    std::thread *serversocketThread;

    void serverSocketHandler(int port);
    void clientHandler(boost::asio::ip::tcp::socket &socket);


public:
    BoostServerNetworkAdapter(boost::asio::io_service &ioService);
    ~BoostServerNetworkAdapter();

    virtual void startServer(const int port);
    virtual void stopServer();
    virtual void sendToAll(std::vector<unsigned char> const &data);
    virtual std::vector<int> getUserInputs();
};

#endif // BOOSTSERVERNETWORKADAPTER_H
