#include <boost/network/protocol/http/client.hpp>
#include <boost/network/uri.hpp>

#include "cc_http_server_client.h"

#ifdef _MSC_VER 
//automatic linking on msvc to openssl
#pragma comment(lib,"ssleay32.lib")
#pragma comment(lib,"libeay32.lib")

#pragma comment(lib,"cppnetlib-client-connections.lib")

#pragma comment(lib,"cppnetlib-server-parsers.lib")

#pragma comment(lib,"cppnetlib-uri.lib")


#endif

using namespace cc_http_server_client;
using namespace boost::network;
using cross_compiler_interface::use_unknown;
using cross_compiler_interface::implement_unknown_interfaces;
using cross_compiler_interface::cr_string;

template<class T>
struct IGetNative
	:public cross_compiler_interface::define_unknown_interface<T,
	// {BC6D04C5-6A8B-437F-934F-998D3BCACB74}
	cross_compiler_interface::uuid<
	0xBC6D04C5,0x6A8B,0x437F,0x93,0x4F,0x99,0x8D,0x3B,0xCA,0xCB,0x74
	>
	>
{
    
    cross_function<IGetNative,0,void*()> Get;

    template<class Class>
    Class& GetAs(){
        return *static_cast<Class*>(Get());
    }

	IGetNative()
        :Get(this)
	{}
};



struct ImplementUri:public implement_unknown_interfaces<ImplementUri,IUri>{

   boost::network::uri::uri u_;

   std::string GetScheme(){return u_.scheme();}
   std::string GetUserInfo(){return u_.user_info();}
   std::string GetHost(){return u_.host();}
   std::string GetPort(){return u_.port();}
   std::string GetPath(){return u_.path();}
   std::string GetQuery(){return u_.query();}
   std::string GetFragment(){return u_.fragment();}
   std::string ToString(){return u_.string();}
   bool IsValid(){return u_.is_valid();}




   ImplementUri(const std::string& s):u_(s){set_mem_fns(); }
   ImplementUri(const boost::network::uri::uri& u):u_(u){set_mem_fns(); }



private:

    void set_mem_fns(){
       auto& imp = *get_implementation<IUri>();

       imp.GetScheme.set_mem_fn<ImplementUri,&ImplementUri::GetScheme>(this);
       imp.GetUserInfo.set_mem_fn<ImplementUri,&ImplementUri::GetUserInfo>(this);
       imp.GetHost.set_mem_fn<ImplementUri,&ImplementUri::GetHost>(this);
       imp.GetPort.set_mem_fn<ImplementUri,&ImplementUri::GetPort>(this);
       imp.GetPath.set_mem_fn<ImplementUri,&ImplementUri::GetPath>(this);
       imp.GetQuery.set_mem_fn<ImplementUri,&ImplementUri::GetQuery>(this);
       imp.GetFragment.set_mem_fn<ImplementUri,&ImplementUri::GetFragment>(this);
       imp.ToString.set_mem_fn<ImplementUri,&ImplementUri::ToString>(this);
       imp.IsValid.set_mem_fn<ImplementUri,&ImplementUri::IsValid>(this);


    }

};


struct ImplementClientRequest
    :public implement_unknown_interfaces<ImplementClientRequest,IClientRequest,IGetNative>
{
    boost::network::http::client::request request_;

    void SetUriString(cr_string s){
        request_.uri(s.to_string());
    }

    void SetUri(use_unknown<IUri> u){
        boost::network::uri::uri uri(u.ToString());

        request_.uri(uri);

    }

     use_unknown<IUri> GetUri(){
        auto u = ImplementUri::create(request_.uri());
        return u.QueryInterface<IUri>();
    }

     void AddHeader(cr_string n,cr_string v){
         request_.add_header(std::make_pair(n.to_string(),v.to_string()));
     }

     void RemoveHeader(cr_string n){
         request_.remove_header(n.to_string());
     }

     HeadersType GetHeaders(){
         HeadersType ret;
         for(auto h: request_.headers()){
             ret.push_back(h);
         }
         return ret;
     }

     std::string GetBody(){
         return request_.body();
     }

     void SetBody(cr_string body){
        request_.body(body.to_string());
     }


     void* GetNative(){
         return this;
     }

     ImplementClientRequest(){
         set_mem_fns();


     }


private:
    void set_mem_fns(){
        auto& imp = *get_implementation<IClientRequest>();
        imp.SetUriString.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::SetUriString>(this);
        imp.SetUri.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::SetUri>(this);
        imp.GetUri.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::GetUri>(this);
        imp.AddHeader.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::AddHeader>(this);
        imp.RemoveHeader.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::RemoveHeader>(this);
        imp.GetHeaders.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::GetHeaders>(this);
        imp.GetBody.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::GetBody>(this);
        imp.SetBody.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::SetBody>(this);

        get_implementation<IGetNative>()->Get.set_mem_fn<ImplementClientRequest,&ImplementClientRequest::GetNative>(this);


    }
};


struct ImplementClientParameters
    :public implement_unknown_interfaces<ImplementClientParameters,IClientParameters>{

        bool follow_redirects_;
        bool cache_resolved_;
        std::string ssl_certificate_;
        std::string ssl_verify_path_;


      bool GetFollowRedirects(){
          return follow_redirects_;
      }

      void SetFollowRedirects(bool b){
          follow_redirects_ = b;
      }

      bool GetCacheResolved(){
          return cache_resolved_;
      }

      void SetCacheResolved(bool b){
          cache_resolved_ = b;
      }
      
      std::string GetSslCertificate(){
          return ssl_certificate_;
      }

      void SetSslCertificate(cr_string s){
          ssl_certificate_ = s.to_string();
      }

      std::string GetSslVerifyPath(){
          return ssl_verify_path_;
      }

      void SetSslVerifyPath(cr_string s){
          ssl_verify_path_ = s.to_string();
      }


      ImplementClientParameters()
          :follow_redirects_(false),cache_resolved_(false)
      {
            auto& imp = *get_implementation<IClientParameters>();

            imp.GetFollowRedirects.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::GetFollowRedirects>(this);
            imp.SetFollowRedirects.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::SetFollowRedirects>(this);
            imp.GetCacheResolved.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::GetCacheResolved>(this);
            imp.SetCacheResolved.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::SetCacheResolved>(this);
            imp.GetSslCertificate.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::GetSslCertificate>(this);
            imp.SetSslCertificate.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::SetSslCertificate>(this);
            imp.GetSslVerifyPath.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::GetSslVerifyPath>(this);
            imp.SetSslVerifyPath.set_mem_fn<ImplementClientParameters,&ImplementClientParameters::SetSslVerifyPath>(this);

      }
};


struct ImplementClientResponse
    :public implement_unknown_interfaces<ImplementClientResponse,IClientResponse>{

        boost::network::http::client::response response_;

        ImplementClientResponse(const boost::network::http::client::response& r)
            :response_(r)
        {
            auto& imp = *get_implementation<IClientResponse>();

            imp.GetSource = [this](){return response_.source();};
            imp.GetDestination = [this](){return response_.destination();};
            imp.GetHeaders = [this]()->HeadersType{
                HeadersType ret;
                for(auto h: response_.headers()){
                    ret.push_back(h);
                }

                return ret;
            
            };
            imp.GetBody = [this](){return response_.body();};
            imp.GetVersion = [this](){return response_.version();};
            imp.GetStatus = [this](){return response_.status();};
            imp.GetStatusMessage = [this](){return response_.status_message();};

            

        }


};

struct ImplementClient
    :public implement_unknown_interfaces<ImplementClient,IClient>{

        boost::network::http::client client_;

        ImplementClient(const boost::network::http::client& c)
            :client_(c){

                auto& imp = *get_implementation<IClient>();

                imp.Get = [this](use_unknown<IClientRequest> req)->use_unknown<IClientResponse>{
                   
                        auto res = client_.get(req.QueryInterface<IGetNative>().GetAs<ImplementClientRequest>()
                        .request_);
                         return ImplementClientResponse::create(res).QueryInterface<IClientResponse>();
                };
                imp.Post = [this](use_unknown<IClientRequest> req)->use_unknown<IClientResponse>{
                        auto res = client_.post(req.QueryInterface<IGetNative>().GetAs<ImplementClientRequest>()
                        .request_);
                         return ImplementClientResponse::create(res).QueryInterface<IClientResponse>();
                };
                imp.Head = [this](use_unknown<IClientRequest> req)->use_unknown<IClientResponse>{
                        auto res = client_.head(req.QueryInterface<IGetNative>().GetAs<ImplementClientRequest>()
                        .request_);
                         return ImplementClientResponse::create(res).QueryInterface<IClientResponse>();
                };
                imp.Put = [this](use_unknown<IClientRequest> req)->use_unknown<IClientResponse>{
                        auto res = client_.put(req.QueryInterface<IGetNative>().GetAs<ImplementClientRequest>()
                        .request_);
                         return ImplementClientResponse::create(res).QueryInterface<IClientResponse>();
                };
                imp.Delete = [this](use_unknown<IClientRequest> req)->use_unknown<IClientResponse>{
                        auto res = client_.delete_(req.QueryInterface<IGetNative>().GetAs<ImplementClientRequest>()
                        .request_);
                         return ImplementClientResponse::create(res).QueryInterface<IClientResponse>();
                };

        }



};


struct ImplementClientCreator
    :public implement_unknown_interfaces<ImplementClientCreator,IClientCreator>{

        struct ImplementClientCreator(){
            
            auto& imp = *get_implementation<IClientCreator>();

            imp.CreateUriFromString = [](cr_string s){
                return ImplementUri::create(s.to_string()).QueryInterface<IUri>();
            };
            imp.CreateUri= [](){return ImplementUri::create("").QueryInterface<IUri>();};
            imp.CreateClientRequest= [](){return ImplementClientRequest::create().QueryInterface<IClientRequest>();};
            imp.CreateClient = []()->use_unknown<IClient>{
                boost::network::http::client c;
                return ImplementClient::create(c)
                .QueryInterface<IClient>();};

            imp.CreateClientWithParameters = [](use_unknown<IClientParameters> p)->use_unknown<IClient>{
                using namespace boost::network::http;
                client client_(_follow_redirects=p.GetFollowRedirects(), _cache_resolved=p.GetCacheResolved(),
                _openssl_certificate=p.GetSslCertificate(),
                _openssl_verify_path=p.GetSslVerifyPath());

                return ImplementClient::create(client_)
                .QueryInterface<IClient>();
            };

            imp.CreateClientParameters = [](){
                return ImplementClientParameters::create().QueryInterface<IClientParameters>();
            };




        }


};