#ifndef CLIENTNETWORKADAPTER_H
#define CLIENTNETWORKADAPTER_H

#include <string>
#include <vector>

class ClientNetworkAdapter
{
public:
    ClientNetworkAdapter();
    virtual ~ClientNetworkAdapter();

    virtual void registerToServer(std::string ipaddress, std::string port) = 0;
    virtual void send(std::vector<unsigned char> &data) = 0;
    virtual void getSnapshot() = 0;
};

#endif // CLIENTNETWORKADAPTER_H
