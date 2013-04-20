

#include <boost/network/protocol/http/client.hpp>
#include <iostream>
#ifdef _MSC_VER 
//automatic linking on msvc to openssl
#pragma comment(lib,"ssleay32.lib")
#pragma comment(lib,"libeay32.lib")

#pragma comment(lib,"cppnetlib-client-connections.lib")

#pragma comment(lib,"cppnetlib-server-parsers.lib")

#pragma comment(lib,"cppnetlib-uri.lib")


#endif



int main(int argc, char * argv[]) {
    using namespace boost::network;

  //  if (argc != 2) { std::cout << "Usage: " << argv[0] << " <url>" << std::endl; return 1; }

    http::client client;
    http::client::request request("https://www.google.com/");
    request << header("Connection", "close");
    http::client::response response = client.get(request);
    std::cout << body(response) << std::endl;

    return 0;
}