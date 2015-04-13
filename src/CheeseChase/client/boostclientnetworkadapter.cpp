#include "boostclientnetworkadapter.h"

using namespace std;
using namespace boost::asio;

BoostClientNetworkAdapter::BoostClientNetworkAdapter(io_service &ioService) :
    ioService(ioService), tcpResolver(ioService)
{

}

BoostClientNetworkAdapter::~BoostClientNetworkAdapter()
{

}

void BoostClientNetworkAdapter::registerToServer(string ipaddress, string port)
{
    ip::tcp::resolver::iterator endpoint = tcpResolver.resolve(
                ip::tcp::resolver::query(ipaddress, port));

    ip::tcp::socket socket(ioService);
    connect(socket, endpoint);

  //  for( ; ; ) {
        array<char, 20> buffer;
        boost::system::error_code errorCode;
        size_t len = socket.read_some(boost::asio::buffer(buffer), errorCode);

  //      if(errorCode == boost::asio::error::eof) {
  //          break;
  /*      } else */ if(errorCode) {
            throw boost::system::system_error(errorCode);
        }

        cout << buffer.data() << endl;
  //  }



}

void BoostClientNetworkAdapter::send(std::vector<unsigned char> &data)
{

}

void BoostClientNetworkAdapter::getSnapshot()
{

}
