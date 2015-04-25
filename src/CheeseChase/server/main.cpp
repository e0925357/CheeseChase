#include <iostream>
#include <boost/asio.hpp>

#include "servernetworkadapter.h"
#include "boostservernetworkadapter.h"

using namespace std;

int main()
{
    boost::asio::io_service ioService;
    ServerNetworkAdapter *networkAdapter = new BoostServerNetworkAdapter(ioService, 2000);
    networkAdapter->startServer();

    delete networkAdapter;

    return 0;
}

