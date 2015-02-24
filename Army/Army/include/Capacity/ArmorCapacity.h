#ifndef _ARMORCAPACITY_H_
#define _ARMORCAPACITY_H_

#include "Capacity.h"

class ArmorCapacity : public Capacity
{
public:
    ArmorCapacity(unsigned int startLevel = 0);
    ArmorCapacity(const ArmorCapacity&);
    ArmorCapacity& operator=(const ArmorCapacity&);
    ~ArmorCapacity();

    virtual void recompute();
};

#endif //_ARMORCAPACITY_H_