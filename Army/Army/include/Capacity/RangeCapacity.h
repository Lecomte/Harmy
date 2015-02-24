#ifndef _RANGECAPACITY_H_
#define _RANGECAPACITY_H_

#include "Capacity.h"

class RangeCapacity : public Capacity
{
public:
    RangeCapacity(unsigned int startLevel = 0);
    RangeCapacity(const RangeCapacity&);
    RangeCapacity& operator=(const RangeCapacity&);
    ~RangeCapacity();

    virtual void recompute();
};

#endif //_RANGECAPACITY_H_