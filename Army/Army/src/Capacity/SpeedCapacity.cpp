#include "Capacity/SpeedCapacity.h"

SpeedCapacity::SpeedCapacity(unsigned int startLevel)
    : Capacity(startLevel)
{}

SpeedCapacity::SpeedCapacity(const SpeedCapacity& s)
    : Capacity(s)
{}

SpeedCapacity& SpeedCapacity::operator=(const SpeedCapacity& s)
{
    if (&s != this)
    {
        Capacity::operator=(s);
    }

    return *this;
}

SpeedCapacity::~SpeedCapacity()
{}

void SpeedCapacity::recompute()
{
    m_value = 1.0f + static_cast<float>(m_level);
}