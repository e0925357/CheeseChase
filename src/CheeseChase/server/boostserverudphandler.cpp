#include "boostserverudphandler.h"

using namespace boost;
using namespace std;

BoostServerUDPHandler::BoostServerUDPHandler(asio::io_service &ioService, int serverPort) :
    ioService(ioService), udpSocket(ioService, asio::ip::udp::endpoint(asio::ip::udp::v4(), serverPort))
{
    receiveThread = new thread(&BoostServerUDPHandler::startThread, this);
}

BoostServerUDPHandler::~BoostServerUDPHandler()
{
    receiveThread->join();
    delete receiveThread;
}

void BoostServerUDPHandler::startThread()
{
    doReceive();
    ioService.run();
}

void BoostServerUDPHandler::doReceive()
{
    asio::ip::udp::endpoint remoteEndpoint;
    udpSocket.async_receive_from(asio::buffer(readBuffer), remoteEndpoint,
                                         boost::bind(&BoostServerUDPHandler::handleReceive, this,
                                                     boost::asio::placeholders::error,
                                                     boost::asio::placeholders::bytes_transferred));
}

void BoostServerUDPHandler::handleReceive(const boost::system::error_code &error, size_t bytes_transfered)
{
    cout << "Success!!" << endl;
    cout << "Message: " << string(readBuffer.begin(), readBuffer.begin()+bytes_transfered) << endl;

    if (!error || error == boost::asio::error::message_size) {
        doReceive();
    } else {
        cout << "dead" << endl;
    }
}
