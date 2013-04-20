
#include "cc_http_server_client.h"
#include <iostream>


using namespace cc_http_server_client;
int main(int argc, char * argv[]) {

    cross_compiler_interface::module m("cc_http_server_client");
    std::string func("GetClientCreator");
    auto creator = cross_compiler_interface::create_unknown(m,func).QueryInterface<IClientCreator>();

    auto client = creator.CreateClient();
    auto request = creator.CreateClientRequest();
    auto uri = creator.CreateUriFromString("https://www.google.com/");
    request.SetUri(uri);
    request.AddHeader("Connection","close");
    auto response = client.Get(request);
    std::cout << response.GetBody();


  //  if (argc != 2) { std::cout << "Usage: " << argv[0] << " <url>" << std::endl; return 1; }

    //http::client client;
    //http::client::request request("https://www.google.com/");
    //request << header("Connection", "close");
    //http::client::response response = client.get(request);
    //std::cout << body(response) << std::endl;

    return 0;
}