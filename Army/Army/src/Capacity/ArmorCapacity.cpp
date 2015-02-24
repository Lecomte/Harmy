#include "Capacity/ArmorCapacity.h"

ArmorCapacity::ArmorCapacity(unsigned int startLevel)
    : Capacity(startLevel)
{}

ArmorCapacity::ArmorCapacity(const ArmorCapacity& c)
    : Capacity(c)
{}

ArmorCapacity& ArmorCapacity::operator=(const ArmorCapacity& c)
{
    if (&c != this)
    {
        Capacity::operator=(c);
    }

    return *this;
}

ArmorCapacity::~ArmorCapacity()
{}

void ArmorCapacity::recompute()
{
    m_value = static_cast<float>(m_level) / 2.0f;
}