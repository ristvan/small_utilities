#ifndef __ACCOUNT_DATA__
#define __ACCOUNT_DATA__

#include <istream>

struct AccountData
{
    std::string accountId;
    int value;

//    friend std::istream& operator>>(std::istream&, AccountData&);
};

std::istream& operator>>(std::istream& inputStream,
                         AccountData& accountData)
{
    inputStream >> accountData.accountId;
    inputStream >> accountData.value;
    return inputStream;
}

#endif
