#include "Capacity/DamageCapacity.h"

DamageCapacity::DamageCapacity(unsigned int startLevel)
    : Capacity(startLevel)
{}

DamageCapacity::DamageCapacity(const DamageCapacity& d)
    : Capacity(d)
{}

DamageCapacity& DamageCapacity::operator=(const DamageCapacity& d)
{
    if (&d != this)
    {
        Capacity::operator=(d);
    }

    return *this;
}

DamageCapacity::~DamageCapacity()
{}

void DamageCapacity::recompute()
{
    m_value = static_cast<float>((1 + m_level)) * 1.5f;
}