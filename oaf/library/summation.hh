#ifndef __SUMMATION_HH__
#define __SUMMATION_HH__

#include "procedure.hh"

template < typename Item, typename Range = Item >
class Summation : public Procedure<Item>
{
public:
    Range result() { return *_result; }
    ~Summation() { if(_inref) delete _result; }

protected:
    Range *_result;
    bool _inref;

    Summation() { _inref = true; _result = new Range; }
    Summation(Range *r) { _inref = false; _result = r; }
    void init() {}
    void body(const Item& e) { if(cond(e)) add(e); }
    virtual void add(const Item& e) = 0;
    virtual bool cond(const Item& e) const { return true;}
};

#endif

