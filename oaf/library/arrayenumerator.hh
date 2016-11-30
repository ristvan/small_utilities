#ifndef _ARRAYENUMERATOR_
#define _ARRAYENUMERATOR_

#include "enumerator.hh"
#include <vector>

template <typename Item>
class ArrayEnumerator : public Enumerator<Item>
{
public:
    ArrayEnumerator(std::vector<Item> *v):_vect(v) {}

    void first()         { _index = 0; }
    void next()          { ++_index; }
    bool end()     const { return _index >= (int)_vect->size(); }
    Item current() const { return (*_vect)[_index]; }

protected:
    std::vector<Item> *_vect;
    int   _index;
};

#endif

