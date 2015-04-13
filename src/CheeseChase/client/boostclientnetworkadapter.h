#ifndef BOOSTCLIENTNETWORKADAPTER_H
#define BOOSTCLIENTNETWORKADAPTER_H

#include <iostream>
#include <array>

#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include "clientnetworkadapter.h"

class BoostClientNetworkAdapter : public ClientNetworkAdapter
{
private:
    boost::asio::io_service &ioService;
    boost::asio::ip::tcp::resolver tcpResolver;

    boost::asio::ip::tcp::socket tcpSocket;

public:
    BoostClientNetworkAdapter(boost::asio::io_service &ioService);
    virtual ~BoostClientNetworkAdapter();

    virtual void registerToServer(std::string ipaddress, std::string port);
    virtual void send(std::vector<unsigned char> &data);
    virtual void getSnapshot();
};

#endif // BOOSTCLIENTNETWORKADAPTER_H
