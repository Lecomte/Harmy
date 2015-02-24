#include "Capacity/RangeCapacity.h"

RangeCapacity::RangeCapacity(unsigned int startLevel)
    : Capacity(startLevel)
{}

RangeCapacity::RangeCapacity(const RangeCapacity& r)
    : Capacity(r)
{}

RangeCapacity& RangeCapacity::operator=(const RangeCapacity& r)
{
    if (&r != this)
    {
        Capacity::operator=(r);
    }

    return *this;
}

RangeCapacity::~RangeCapacity()
{}

void RangeCapacity::recompute()
{
    m_value = 10.0f + static_cast<float>(m_level * 2);
}