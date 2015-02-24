#ifndef _RELOADCAPACITY_H_
#define _RELOADCAPACITY_H_

#include "Capacity.h"

class ReloadCapacity : public Capacity
{
public:
    ReloadCapacity(unsigned int startLevel = 0);
    ReloadCapacity(const ReloadCapacity&);
    ReloadCapacity& operator=(const ReloadCapacity&);
    ~ReloadCapacity();

    virtual void init();
    virtual void recompute();

    float getCurrentReload() const;
    void setCurrentReload(float max);

    void updateValue();

    virtual void upgrade();
    virtual void downgrade();

    virtual void setLevel(unsigned int level);

protected:
    float m_curReload;
};

#endif //_RELOADCAPACITY_H_