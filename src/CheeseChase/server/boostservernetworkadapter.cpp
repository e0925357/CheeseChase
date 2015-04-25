#include "boostservernetworkadapter.h"

using namespace std;
using namespace boost;

int BoostServerNetworkAdapter::uuidGenerator = 0;

BoostServerNetworkAdapter::BoostServerNetworkAdapter(asio::io_service &ioService, const int serverPort) :
    ioService(ioService), tcpAcceptor(ioService, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), serverPort)), running(true),
    serversocketThread(nullptr), serverPort(serverPort)
{
}

BoostServerNetworkAdapter::~BoostServerNetworkAdapter()
{

}

void BoostServerNetworkAdapter::startServer()
{
    if(serversocketThread == nullptr) {
        serversocketThread = new thread(&BoostServerNetworkAdapter::serverSocketHandler, this);
    }

    //TODO: Remove this line when main thread runs longer than a few seconds
    serversocketThread->join();
}

void BoostServerNetworkAdapter::stopServer()
{
    if(serversocketThread != nullptr) {
        delete serversocketThread;
        serversocketThread = nullptr;
    }
}

void BoostServerNetworkAdapter::sendToAll(vector<unsigned char> const &data)
{
}

vector<int> BoostServerNetworkAdapter::getUserInputs()
{
}

void BoostServerNetworkAdapter::serverSocketHandler()
{
    while(running) {
        asio::ip::tcp::socket *socket = new asio::ip::tcp::socket(ioService);
        tcpAcceptor.accept(*socket);

        sockets.push_back(socket);
        thread t1(&BoostServerNetworkAdapter::clientHandler, this, std::ref(*socket));
        t1.join();  // Change
    }
}

void BoostServerNetworkAdapter::clientHandler( asio::ip::tcp::socket &socket )
{
    // Wait for hello message
    std::array<char, 128> buf;
    buf.fill(' ');
    system::error_code ec;

    size_t len = socket.read_some(asio::buffer(buf), ec);
    if(ec == asio::error::eof) {
        return; // Socket closed by peer.
    } else if(ec) {
        throw system::system_error(ec);
    }
    string hellomessage(std::begin(buf), std::end(buf));
    algorithm::trim(hellomessage);
    cout << hellomessage << endl;

    // Parse UDP port from string
    regex checkExpr("!hello ([0-9]+)( ([0-9]+))?");
    smatch results;

    int udpPort;
    int uuid;
    if(regex_match(hellomessage, results, checkExpr)) {
        udpPort = lexical_cast<int>(results[1]);
        cout << "UDP Port received: " << results[1] << endl;

        try {
            uuid = lexical_cast<int>(results[3]);
            cout << "UUID: " << results[3] << endl;
        } catch (boost::exception &e) {
            cout << "No UUID transmitted" << endl;
            uuid = -1;
        }
    } else {
        cout << "did not match :(" <<  endl;
        return;
    }

    usersLock.lock();
    map<int, int>::iterator uuidIter = users.find(uuid);
    if(uuid == -1 || uuidIter == users.end()) {
        // create new UUID for user
        uuid = uuidGenerator++;
        users.insert(pair<int, int>(uuid, udpPort));        // TODO: Replace with object that stores IP-Address too

        // send static information to peer
        string message = "!information " + to_string(uuid);
        asio::write(socket, asio::buffer(message));
    } else {
        // Update information
        uuidIter->second = udpPort;

        // Send ok
        string message = "!ok";
        asio::write(socket, asio::buffer(message));
    }
    usersLock.unlock();

    asio::ip::udp::endpoint endPoint(socket.remote_endpoint().address(), 6654);
    asio::io_service localService;
    BoostServerUDPHandler *udpHandler = new BoostServerUDPHandler(localService, endPoint, serverPort);

    // Listen to TCP stream. If it ends, kill spawned UDP thread and end this thread
    len = socket.read_some(asio::buffer(buf), ec);
    if(ec == asio::error::eof) {
        cout << "EOF!!" << endl;
        localService.stop();
        delete udpHandler;
        return; // Socket closed by peer.
    } else if(ec) {
        throw system::system_error(ec);
    }
}

