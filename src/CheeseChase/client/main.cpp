#include <iostream>
#include <thread>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

void foo() {
    cout << "thread client" << endl;
}

int main()
{
    io_service ioService;



    std::thread t1(foo);
    cout << "Client: Hello World!" << endl;
    t1.join();
    return 0;
}

