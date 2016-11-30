#ifndef __SELECTION__
#define __SELECTION__

#include "procedure.hh"

template < class Item >
class Selection : public Procedure<Item>
{
protected:
    void init() {}
    virtual bool cond(const Item& e) const = 0;
    void body(const Item& e) {}
    bool loopCond() const
    {
        return !cond(Procedure<Item>::_enor->current());
    }
};

#endif
