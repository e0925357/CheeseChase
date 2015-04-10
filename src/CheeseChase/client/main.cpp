#include <iostream>
#include <thread>


using namespace std;

void foo() {
    cout << "thread client" << endl;
}

int main()
{
    std::thread t1(foo);
    cout << "Client: Hello World!" << endl;
    t1.join();
    return 0;
}

