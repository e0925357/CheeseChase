#include "boostclientnetworkadapter.h"

using namespace std;
using namespace boost::asio;

BoostClientNetworkAdapter::BoostClientNetworkAdapter(io_service &ioService) :
    ioService(ioService), tcpResolver(ioService), tcpSocket(ioService)
{

}

BoostClientNetworkAdapter::~BoostClientNetworkAdapter()
{

}

void BoostClientNetworkAdapter::registerToServer(string ipaddress, string port)
{
    // Get connection to server
    ip::tcp::resolver::iterator endpoint = tcpResolver.resolve(
                ip::tcp::resolver::query(ipaddress, port));

    connect(tcpSocket, endpoint);

    // Send hello message to server
    string hellomessage = "!hello 555";
    write(tcpSocket, buffer(hellomessage));

    // Receive answer
    std::array<char, 128> buf;
    buf.fill(' ');
    boost::system::error_code ec;

    size_t len = tcpSocket.read_some(buffer(buf), ec);
    if(ec == error::eof) {
        return; // Socket closed by server.
    } else if(ec) {
        throw boost::system::system_error(ec);
    }
    string helloanswer(std::begin(buf), std::end(buf));
    boost::algorithm::trim(helloanswer);
    cout << helloanswer << endl;

    // Parse answer
    // TODO!
}

void BoostClientNetworkAdapter::send(std::vector<unsigned char> &data)
{

}

void BoostClientNetworkAdapter::getSnapshot()
{
    //  for( ; ; ) {
          array<char, 20> buffer;
          boost::system::error_code errorCode;
          size_t len = tcpSocket.read_some(boost::asio::buffer(buffer), errorCode);

    //      if(errorCode == boost::asio::error::eof) {
    //          break;
    /*      } else */ if(errorCode) {
              throw boost::system::system_error(errorCode);
          }

          cout << buffer.data() << endl;
    //  }


}
