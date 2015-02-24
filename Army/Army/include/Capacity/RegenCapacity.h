#ifndef _REGENCAPACITY_H_
#define _REGENCAPACITY_H_

#include "Capacity.h"

class RegenCapacity : public Capacity
{
public:
    RegenCapacity(unsigned int startLevel = 0);
    RegenCapacity(const RegenCapacity&);
    RegenCapacity& operator=(const RegenCapacity&);
    ~RegenCapacity();

    virtual void recompute();
};

#endif //_REGENCAPACITY_H_