#ifndef __COUNTING_HPP__
#define __COUNTING_HPP__

#include "summation.hh"

template < typename Item >
class Counting : public Summation<Item, int>
{
public:
    Counting():Summation<Item,int>(){}

protected:

    void init()             { *Summation<Item,int>::_result = 0; }
    void add(const Item& e) { ++*Summation<Item,int>::_result; }
};

#endif

