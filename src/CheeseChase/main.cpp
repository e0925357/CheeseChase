#include <iostream>
#include <thread>


using namespace std;

void foo() {
    cout << "Hello World!" << endl;
}

int main()
{
    std::thread t1(foo);
    cout << "Hello World!" << endl;
    t1.join();
    return 0;
}

