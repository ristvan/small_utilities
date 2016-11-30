//#include <iostream>
//#include <string>

#include "StringTokenizer.hh"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Number of arguments: " << argc << endl;
    if (argc <= 1)
    {
       return 0;
    }
   
    string tokenizable = argv[1];
    
    StringTokenizer tokenizer(tokenizable);

    cout << "Number of Tokens: " << tokenizer.countTokens() << endl;

    cout << "Tokens are:" << endl;
    while ( tokenizer.hasMoreToken() )
    {
        cout << "\t\"" << tokenizer.nextToken() << "\"" << endl;
    }

    return 0;
}

//end of file

