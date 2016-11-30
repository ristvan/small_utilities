#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Too few input arguments" << endl;
        return 1;
    }
    int num = atoi(argv[1]);
    cout << num << " -> " << hex << num << endl;
    return 0;
}
