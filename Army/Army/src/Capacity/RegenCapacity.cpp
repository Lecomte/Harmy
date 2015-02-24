#include "Capacity/RegenCapacity.h"

RegenCapacity::RegenCapacity(unsigned int startLevel)
    : Capacity(startLevel)
{}

RegenCapacity::RegenCapacity(const RegenCapacity& r)
    : Capacity(r)
{}

RegenCapacity& RegenCapacity::operator=(const RegenCapacity& r)
{
    if (&r != this)
    {
        Capacity::operator=(r);
    }

    return *this;
}

RegenCapacity::~RegenCapacity()
{}

void RegenCapacity::recompute()
{
    m_value = static_cast<float>(m_level) / 1000.0f;
}