#ifndef SERVERNETWORKADAPTER_H
#define SERVERNETWORKADAPTER_H

#include <vector>

class ServerNetworkAdapter
{
public:
    ServerNetworkAdapter();
    virtual ~ServerNetworkAdapter();

    virtual void startServer() = 0;
    virtual void stopServer() = 0;
    virtual void sendToAll(std::vector<unsigned char> const &data) = 0;
    virtual std::vector<int> getUserInputs() = 0;
};

#endif // SERVERNETWORKADAPTER_H
