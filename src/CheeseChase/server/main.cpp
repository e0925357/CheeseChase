#include <iostream>
#include <thread>


using namespace std;

void foo() {
    cout << "thread server" << endl;
}

int main()
{
    std::thread t1(foo);
    cout << "Server: Hello World!" << endl;
    t1.join();
    return 0;
}

