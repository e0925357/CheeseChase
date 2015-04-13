#include <iostream>
#include <thread>
#include <boost/asio.hpp>

#include "servernetworkadapter.h"
#include "boostservernetworkadapter.h"

using namespace std;

void foo() {
    cout << "thread server" << endl;
}

int main()
{
//    std::thread t1(foo);
//    cout << "Server: Hello World!" << endl;
//    t1.join();

    boost::asio::io_service ioService;
    ServerNetworkAdapter *networkAdapter = new BoostServerNetworkAdapter(ioService);
    networkAdapter->startServer(3000);

    delete networkAdapter;

    return 0;
}

