#ifndef _DAMAGECAPACITY_H_
#define _DAMAGECAPACITY_H_

#include "Capacity.h"

class DamageCapacity : public Capacity
{
public:
    DamageCapacity(unsigned int startLevel = 0);
    DamageCapacity(const DamageCapacity&);
    DamageCapacity& operator=(const DamageCapacity&);
    ~DamageCapacity();

    virtual void recompute();
};

#endif //_DAMAGECAPACITY_H_