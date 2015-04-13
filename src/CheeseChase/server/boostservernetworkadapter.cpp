#include "boostservernetworkadapter.h"

using namespace std;
using namespace boost::asio;

BoostServerNetworkAdapter::BoostServerNetworkAdapter(io_service &ioService) :
    ioService(ioService), tcpAcceptor(ioService, ip::tcp::endpoint(ip::tcp::v4(), 2000)), running(true),
    serversocketThread(nullptr)
{
}

BoostServerNetworkAdapter::~BoostServerNetworkAdapter()
{

}

void BoostServerNetworkAdapter::startServer(const int port)
{
    if(serversocketThread == nullptr) {
        serversocketThread = new thread(&BoostServerNetworkAdapter::serverSocketHandler, this, port);
    }

    //TODO: Remove this line when main thread runs longer than a few seconds
    serversocketThread->join();
}

void BoostServerNetworkAdapter::stopServer()
{
    if(serversocketThread != nullptr) {
        delete serversocketThread;
        serversocketThread = nullptr;
    }
}

void BoostServerNetworkAdapter::sendToAll(vector<unsigned char> const &data)
{
}

vector<int> BoostServerNetworkAdapter::getUserInputs()
{
}

void BoostServerNetworkAdapter::serverSocketHandler(int port)
{
    while(running) {
        ip::tcp::socket *socket = new ip::tcp::socket(ioService);
        tcpAcceptor.accept(*socket);

        sockets.push_back(socket);
        thread t1(&BoostServerNetworkAdapter::clientHandler, this, ref(*socket));
        t1.join();  // Change
    }
}

void BoostServerNetworkAdapter::clientHandler( ip::tcp::socket &socket )
{
    std::string message("Hello from Server");
    boost::asio::write(socket, boost::asio::buffer(message));
}

