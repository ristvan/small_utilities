#ifndef __SEQINFILEENUMERATOR__
#define __SEQINFILEENUMERATOR__

#include <fstream>
#include <typeinfo>

#include "enumerator.hh"

template <typename Item>  // Item implementálja az operator>>-t
class SeqInFileEnumerator : public Enumerator<Item>
{
public:
    enum Exceptions { OPEN_ERROR };

    SeqInFileEnumerator(const std::string& fileName)
    {
        inputStream.open(fileName.c_str());
        if (inputStream.fail())
        {
            throw OPEN_ERROR;
        }
        if (typeid(Item) == typeid(char))
        {
            inputStream.unsetf(std::ios::skipws);
        }
    }

    void first()         { next(); }
    void next()          { inputStream >> df; }
    bool end()     const { return inputStream.eof(); }
    Item current() const { return df; }

protected:
    std::ifstream inputStream;
    Item          df;
};

#endif

