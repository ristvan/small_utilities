#ifndef __LINSEARCH__
#define __LINSEARCH__

#include "procedure.hh"

template < typename Item, bool optimist = false>
class LinSearch : public Procedure<Item>
{
public:
    bool found()  const{ return _l; }
    Item elem()   const{ return _elem; }

protected:
    bool _l;
    Item _elem;

    void init() { _l = optimist; }
    void body(const Item& e) { _l = cond(_elem = e); }
    bool whileCond(const Item& e) const { return optimist ? _l : !_l; }

    virtual bool cond(const Item& e) const = 0;
};

endif

