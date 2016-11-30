#include <iostream>
#include <string>

#include <string>
#include <algorithm>

char toupper(char ch)
{
    return ('a' <= ch && ch <= 'z') ? (ch & ~0x20) : ch;
}

char tolower(char ch)
{
    return ('A' <= ch && ch <= 'Z') ? (ch | 0x20) : ch;
}

std::string toLowerCase(std::string str)
{
//    std::string tmp(str);
//    std::transform(str.begin(), str.end(), tmp.begin(), tolower);
//    std::transform(tmp.begin(), tmp.end(), tolower);
    for (size_t idx = 0; idx < str.length(); ++idx)
    {
        str[idx] = tolower(str[idx]);
    }
    return str;
}
std::string toUpperCase(std::string& str)
{
//    std::string tmp(str);
//    std::transform(str.begin(), str.end(), tmp.begin(), toupper);
//    std::transform(tmp.begin(), tmp.end(), toupper);
    for (size_t idx = 0; idx < str.length(); ++idx)
    {
        str[idx] = toupper(str[idx]);
    }
    return str;
}


class BlockTrace
{
public:
    BlockTrace(const char* blockName);
    virtual ~BlockTrace();
    int getNum() const { return num; }
private:
    void* operator new(size_t) throw() { return NULL; }
    int num;
    std::string blockName_;
};

BlockTrace::BlockTrace(const char* blockName) : num(1), blockName_(blockName)
{
    std::cout << "++>Start: " << blockName_ << " <++" << std::endl;
    std::cout << "addr obj: " << this << std::endl;
    std::cout << "addr num: " << &num << std::endl;
}

BlockTrace::~BlockTrace()  
{
    std::cout << "++>End: " << blockName_ << " <++" << std::endl;
}

class TestBlock : public BlockTrace
{
public:
    TestBlock() : BlockTrace("TestBlock class") {};
    void* operator new(size_t size) throw() { return ::operator new(size) ; }
};
BlockTrace global("Global");
static BlockTrace staticBT("Static");

class help
{
public:
  help() {}
  int no;
  std::string str;
};

int main(int, char* argv[])
{
    BlockTrace trace("main");
    TestBlock *tbp = new TestBlock;
    std::cout << "num: " << tbp->getNum() << std::endl;
    std::cout << "tbp addr: " << &tbp << std::endl;
//    unsigned int addr = reinterpret_cast<int>(tbp);
//    std::ios_base::fmtflags tmp = std::cout.flags(std::ios_base::hex | std::ios_base::showbase);
//    std::cout << "-addr: " << addr << std::endl;
//    std::cout.flags(tmp);
//    help *ch = reinterpret_cast<help*>(addr);
//    std::cout << "help addr: " << ch << std::endl;
//    std::cout << "help no: " << ch->no << std::endl;
//    ch->no = 28;
//    std::cout << *((int*)(addr + 4)) << std::endl;
    TestBlock &traceRef = *tbp;
    std::cout << "num: " << tbp->getNum() << std::endl;
    std::cout << "Hello World" << std::endl;
    std::cout << "trace addr   : " << tbp << std::endl;
    std::cout << "traceRef addr: " << &traceRef << std::endl;
    TestBlock *delPtr = &traceRef;
    delete delPtr;
    
    std::string txt1 = "Hello World";
    std::string txt2 = "AlFa/BeTa-GaMma_r09";
    
    std::cout << txt1 << " -> " << toLowerCase(txt1) << std::endl;
    std::cout << txt1 << " -> " << toUpperCase(txt1) << std::endl;
    std::cout << txt2 << " -> " << toLowerCase(txt2) << std::endl;
    std::cout << txt2 << " -> " << toUpperCase(txt2) << std::endl;

    
    return 0;
}

// end of file

