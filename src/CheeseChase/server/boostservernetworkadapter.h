#ifndef BOOSTSERVERNETWORKADAPTER_H
#define BOOSTSERVERNETWORKADAPTER_H

#include <thread>
#include <map>
#include <vector>
#include <cstdlib>
#include <mutex>
#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "servernetworkadapter.h"

class BoostServerNetworkAdapter : public ServerNetworkAdapter
{
private:
    static int uuidGenerator;

    bool running;
    std::map<int, int> users;   // UUID to UDP mapping
    std::mutex usersLock;
    std::mutex udpEndpointsLock;
    const int serverPort;

    // Networking
    boost::asio::io_service &ioService;
    boost::asio::ip::tcp::acceptor tcpAcceptor;
    std::vector<boost::asio::ip::tcp::socket*> sockets;

    std::vector<boost::asio::ip::udp::endpoint> udpEndpoints;

    // Threading
    std::thread *serversocketThread;


    void serverSocketHandler();
    void clientHandler(boost::asio::ip::tcp::socket &socket);
    void clientUdpHandler(boost::asio::ip::udp::socket &socket);


public:
    BoostServerNetworkAdapter(boost::asio::io_service &ioService, const int serverPort);
    ~BoostServerNetworkAdapter();

    virtual void startServer();
    virtual void stopServer();
    virtual void sendToAll(std::vector<unsigned char> const &data);
    virtual std::vector<int> getUserInputs();
};

#endif // BOOSTSERVERNETWORKADAPTER_H
