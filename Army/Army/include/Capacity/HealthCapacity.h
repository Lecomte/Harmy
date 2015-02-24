#ifndef _HEALTHCAPACITY_H_
#define _HEALTHCAPACITY_H_

#include "Capacity.h"

class HealthCapacity : public Capacity
{
public:
    HealthCapacity(unsigned int startLevel = 0);
    HealthCapacity(const HealthCapacity&);
    HealthCapacity& operator=(const HealthCapacity&);
    ~HealthCapacity();

    virtual void init();
    virtual void recompute();

    float getCurLife() const;
    void setCurLife(float life);

    void addLife(float life);
    void removeLife(float life);

    virtual void upgrade();
    virtual void downgrade();

    virtual void setLevel(unsigned int level);

protected:
    float m_curLife;
};

#endif //_HEALTHCAPACITY_H_