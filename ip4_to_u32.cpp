#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef unsigned int U32;

class InvalidIpAddressException
{
public:
   typedef enum IpAddressProblem
   {
       TooManyOctets = 1,
       TooFewOctets,
       InvalidNumberInOctet
   } IpAddressProblem;
public:
    InvalidIpAddressException(IpAddressProblem problem) : problem_(problem) { }//cerr << "Exception created" << endl; }
    void Message();
    virtual ~InvalidIpAddressException() { }//cerr << "Exception deleted" << endl; }
private:
    IpAddressProblem problem_;
};

void InvalidIpAddressException::Message()
{
    switch (problem_)
    {
    case TooManyOctets:
    {
       cerr << "Too many octets!" << endl;
       break;
    }
    case TooFewOctets:
    {
       cerr << "Too few octets!" << endl;
       break;
    }
    case InvalidNumberInOctet:
    {
       cout << "Invalid number in octet!" << endl;
       break;
    }
    }
}

class IPv4ToU32
{
public:
    static U32 convert(const string &ipv4);
};

U32 IPv4ToU32::convert(const string &ipv4)
{
    int from = 0;
    int to = 0;
    U32 ip_num = 0;

    int dot_nr = 0;
    while ( (to  = ipv4.find(".", from)) >= 0 )
    {
        dot_nr ++;
        if ( dot_nr > 3 )
        {
//            throw new InvalidIpAddressException();
            throw InvalidIpAddressException(InvalidIpAddressException::TooManyOctets);
        }
//        cout << "first . : " << to << endl;
//        cout << "substring: " << ip.substr(from, to - from) << endl;
        ip_num *= 256;
        ip_num += strtoul(ipv4.substr(from, to - from).c_str(), NULL, 10);
//        cout << "num : " << ip_num << endl;
        from = to + 1;
    }
    if ( dot_nr < 3 )
    {
        throw InvalidIpAddressException( InvalidIpAddressException::TooFewOctets);
    }
//    cout << "last substring: " << ip.substr(from) << endl;
    ip_num *= 256;
    ip_num += strtoul(ipv4.substr(from).c_str(), NULL, 10);
//    cout << "num : " << ip_num << endl;
    return ip_num;
}

int main(int argc, char* argv[])
{
    if ( argc != 2 )
    {
        cerr << endl;
        cerr << "Usage:" << endl;
        cerr << "\t" << argv[0] << " <ip_address>" << endl;
        cerr << "\t\tip_address: a valid ip address (eg. 168.192.0.254)" << endl;
        cerr << endl;
        return 1;
    }
    string ip(argv[1]);
    try
    {
        U32 ip_num = IPv4ToU32::convert(ip);
//    cout << "ip: " << ip << endl;
        cout << ip << " -> " << ip_num << " (";
        ios_base::fmtflags tmp = cout.flags(ios_base::hex | ios_base::showbase);
        cout << ip_num;
        cout.flags(tmp);
        cout << ")" << endl;
    }
     catch (InvalidIpAddressException *ex)
    {
        cerr << "Invalid IP address" << endl;
        delete ex;
    }
    catch (InvalidIpAddressException &ex)
    {
        cerr << "Invalid IP address -- with reference" << endl;
        ex.Message();
    }
    return 0;
}

// end of file

