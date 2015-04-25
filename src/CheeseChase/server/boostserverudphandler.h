#ifndef BOOSTSERVERUDPHANDLER_H
#define BOOSTSERVERUDPHANDLER_H

#include <thread>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <array>

class BoostServerUDPHandler
{
private:
    boost::asio::io_service &ioService;
    boost::asio::ip::udp::socket udpSocket;
    boost::asio::ip::udp::endpoint clientEndpoint;

    std::array<char, 128> readBuffer;
    std::thread *receiveThread;

public:
    BoostServerUDPHandler(boost::asio::io_service &ioService, boost::asio::ip::udp::endpoint &clientEndpoint, int serverPort);
    ~BoostServerUDPHandler();

    void startThread();
    void doReceive();
    void handleReceive(const boost::system::error_code &error, size_t bytes_transfered);
};

#endif // BOOSTSERVERUDPHANDLER_H
