#include <iostream>

using namespace std;

const int NUMBER_OF_AS = 4;

class A
{
public:
    A();
    ~A();
    A& operator=(const A&);
    void write() const;
private:
    char *value;
};

A::A() : value(new char[10])
{
    value[0] = 'a';
    value[1] = 'l';
    value[2] = 'm';
    value[3] = 'a';
    value[4] = '\0';

    cout << "--> ctor: A (" << value << ")" << endl;
}

A::~A()
{
    cout << "--> dtor: A" << endl;
    delete[] value;
}

A& A::operator=(const A&)
{
    cout << "--> operator=(): A" << endl;
}

void A::write() const
{
    cout << "value = '" << value << "'" << endl;
}

class B
{
public:
    B();
    ~B();

    void write() const;

private:
    A as[NUMBER_OF_AS];
};

B::B()
{
    cout << "ctor: B" << endl;
    for (int i = 0; i < NUMBER_OF_AS; ++i)
    {
        as[i] = A();
    }
}

B::~B()
{
    cout << "ctor: B" << endl;
}

void B::write() const
{
    for(int i = 0; i < NUMBER_OF_AS; ++i)
    {
        cout << "**-->";
        as[i].write();
    }
}

int main(int argc, char* argv[])
{
    B b;
    b.write();
}

