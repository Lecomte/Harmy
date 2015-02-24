#ifndef _SPEEDCAPACITY_H_
#define _SPEEDCAPACITY_H_

#include "Capacity.h"

class SpeedCapacity : public Capacity
{
public:
    SpeedCapacity(unsigned int startLevel = 0);
    SpeedCapacity(const SpeedCapacity&);
    SpeedCapacity& operator=(const SpeedCapacity&);
    ~SpeedCapacity();

    virtual void recompute();
};

#endif //_SPEEDCAPACITY_H_