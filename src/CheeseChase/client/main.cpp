#include <iostream>
#include <thread>
#include <boost/asio.hpp>

#include "clientnetworkadapter.h"
#include "boostclientnetworkadapter.h"

using namespace std;
using namespace boost::asio;

void foo() {
    cout << "thread client" << endl;
}

int main()
{
    std::thread t1(foo);
    cout << "Client: Hello World!" << endl;
    t1.join();
    io_service ioService;

    ClientNetworkAdapter *clientNetworkAdapter = new BoostClientNetworkAdapter(ioService);
    clientNetworkAdapter->registerToServer("localhost", "2000");

    return 0;
}

