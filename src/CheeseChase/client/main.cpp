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

    string message = "Client message";
    vector<unsigned char> buffer;
    buffer.insert(buffer.end(), message.begin(), message.end());
    clientNetworkAdapter->send(buffer);


    clientNetworkAdapter->send(buffer);
    clientNetworkAdapter->send(buffer);

    return 0;
}

