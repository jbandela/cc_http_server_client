#include <cross_compiler_interface/interface_unknown.hpp>

namespace cc_http_server_client{
    using cross_compiler_interface::cross_function;
    using cross_compiler_interface::cr_string;
    using cross_compiler_interface::use_unknown;

    typedef std::vector<std::pair<std::string,std::string>> HeadersType;


    template<class T>
    struct IUri
        :public cross_compiler_interface::define_unknown_interface<T,
        // {E1E0728D-C8DF-4FDE-AB90-079F02CE8F8B}
        cross_compiler_interface::uuid<
        0xE1E0728D,0xC8DF,0x4FDE,0xAB,0x90,0x07,0x9F,0x02,0xCE,0x8F,0x8B
        >
        >
    {

        cross_function<IUri,0,std::string()> GetScheme;
        cross_function<IUri,1,std::string()> GetUserInfo;
        cross_function<IUri,2,std::string()> GetHost;
        cross_function<IUri,3,std::string()> GetPort;
        cross_function<IUri,4,std::string()> GetPath;
        cross_function<IUri,5,std::string()> GetQuery;
        cross_function<IUri,6,std::string()> GetFragment;
        cross_function<IUri,7,std::string()> ToString;
        cross_function<IUri,8,bool()> IsValid;

        IUri()
            :GetScheme(this),GetUserInfo(this),GetHost(this),GetPort(this),GetPath(this),
            GetQuery(this),GetFragment(this),ToString(this),IsValid(this)
        {}
    };



    template<class T>
    struct IClientRequest
        :public cross_compiler_interface::define_unknown_interface<T,
        // {58CD3758-45F4-46D1-934D-BBCE5C7A4312}
        cross_compiler_interface::uuid<
        0x58CD3758,0x45F4,0x46D1,0x93,0x4D,0xBB,0xCE,0x5C,0x7A,0x43,0x12
        >
        >
    {
        cross_function<IClientRequest,0,void(cr_string)> SetUriString;
        cross_function<IClientRequest,1,void(use_unknown<IUri>)> SetUri;
        cross_function<IClientRequest,2,use_unknown<IUri>()> GetUri;
        cross_function<IClientRequest,3,void(cr_string,cr_string)> AddHeader;
        cross_function<IClientRequest,4,void(cr_string)> RemoveHeader;
        cross_function<IClientRequest,5,HeadersType()> GetHeaders;
        cross_function<IClientRequest,6,std::string()> GetBody;
        cross_function<IClientRequest,7,void(cr_string)> SetBody;



        IClientRequest()
            :SetUriString(this),SetUri(this),GetUri(this),AddHeader(this),
            RemoveHeader(this),GetHeaders(this),GetBody(this),SetBody(this)
        {}
    };

    template<class T>
struct IClientParameters
	:public cross_compiler_interface::define_unknown_interface<T,
	// {5E6A0CCC-A0EB-4028-9FF1-0783142E4682}
	cross_compiler_interface::uuid<
	0x5E6A0CCC,0xA0EB,0x4028,0x9F,0xF1,0x07,0x83,0x14,0x2E,0x46,0x82
	>
	>
{
    cross_function<IClientParameters,0,bool()>GetFollowRedirects;
    cross_function<IClientParameters,1,void(bool)>SetFollowRedirects;
    cross_function<IClientParameters,2,bool()> GetCacheResolved;
    cross_function<IClientParameters,3,void(bool)> SetCacheResolved;
    cross_function<IClientParameters,4,std::string()> GetSslCertificate;
    cross_function<IClientParameters,5,void(cr_string)>SetSslCertificate;
    cross_function<IClientParameters,6,std::string()> GetSslVerifyPath;
    cross_function<IClientParameters,7,void(cr_string)>SetSslVerifyPath;




	IClientParameters()
        :GetFollowRedirects(this),SetFollowRedirects(this),GetCacheResolved(this),
        SetCacheResolved(this),GetSslCertificate(this),SetSslCertificate(this),
        GetSslVerifyPath(this),SetSslVerifyPath(this)
	{}
};
template<class T>
struct IClientResponse
	:public cross_compiler_interface::define_unknown_interface<T,
	// {ECBE50DB-FB2D-498F-805B-58E353C2EA34}
	cross_compiler_interface::uuid<
	0xECBE50DB,0xFB2D,0x498F,0x80,0x5B,0x58,0xE3,0x53,0xC2,0xEA,0x34
	>
	>
{

    cross_function<IClientResponse,0,std::string()>GetSource;
    cross_function<IClientResponse,1,std::string()>GetDestination;
    cross_function<IClientResponse,2,HeadersType()>GetHeaders;
    cross_function<IClientResponse,3,std::string()>GetBody;
    cross_function<IClientResponse,4,std::string()>GetVersion;
    cross_function<IClientResponse,5,std::uint16_t()>GetStatus;
    cross_function<IClientResponse,6,std::string()>GetStatusMessage;



	IClientResponse()
        :GetSource(this),GetDestination(this),GetHeaders(this),GetBody(this),
        GetVersion(this),GetStatus(this),GetStatusMessage(this)
	{}

};


    template<class T>
struct IClient
	:public cross_compiler_interface::define_unknown_interface<T,
	// {25021867-2CEE-4097-B2DA-AE72ED18D01E}
	cross_compiler_interface::uuid<
	0x25021867,0x2CEE,0x4097,0xB2,0xDA,0xAE,0x72,0xED,0x18,0xD0,0x1E
	>
	>
{

    cross_function<IClient,0,use_unknown<IClientResponse>(use_unknown<IClientRequest>)> Get;
    cross_function<IClient,1,use_unknown<IClientResponse>(use_unknown<IClientRequest>)> Post;
    cross_function<IClient,2,use_unknown<IClientResponse>(use_unknown<IClientRequest>)> Head;
    cross_function<IClient,3,use_unknown<IClientResponse>(use_unknown<IClientRequest>)> Put;
    cross_function<IClient,4,use_unknown<IClientResponse>(use_unknown<IClientRequest>)> Delete;


	IClient()
        :Get(this),Post(this),Head(this),Put(this),Delete(this)
	{}
};


    template<class T>
    struct IClientCreator
        :public cross_compiler_interface::define_unknown_interface<T,
        // {B8FEE778-3F9C-449D-B47B-99D9E9ED0303}
        cross_compiler_interface::uuid<
        0xB8FEE778,0x3F9C,0x449D,0xB4,0x7B,0x99,0xD9,0xE9,0xED,0x03,0x03
        >
        >
    {
        cross_function<IClientCreator,0,use_unknown<IUri>(cr_string)> CreateUriFromString;
        cross_function<IClientCreator,1,use_unknown<IUri>()> CreateUri;
        cross_function<IClientCreator,2,use_unknown<IClientRequest>()> CreateClientRequest;
        cross_function<IClientCreator,3,use_unknown<IClient>()> CreateClient;
        cross_function<IClientCreator,4,use_unknown<IClient>(use_unknown<IClientParameters>)>
            CreateClientWithParameters;
        cross_function<IClientCreator,5,use_unknown<IClientParameters>()> CreateClientParameters;


        IClientCreator()
            :CreateUriFromString(this),CreateUri(this),CreateClientRequest(this),
            CreateClient(this),CreateClientWithParameters(this),CreateClientParameters(this)
        {}
    };


}