#include <boost/locale.hpp>
#include <iostream>
#include <ctime>

int main()
{
    using namespace boost::locale;
    using namespace std;
    generator gen;

    gen.add_messages_path(".");
    gen.add_messages_domain("DeviceResources");
    // std::locale::global(gen("nl_NL")); 
    std::locale::global(gen("en_US")); 

    cout << translate("EmptyList").str(); 
}

// g++ -std=c++14 locale.cpp -I/opt/local/include -w /usr/local/lib/libboost_locale-mt.a /usr/local/lib/libboost_system-mt.dylib /usr/lib/libiconv.dylib
