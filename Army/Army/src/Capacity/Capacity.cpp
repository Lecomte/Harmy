#include "Capacity/Capacity.h"

Capacity::Capacity(unsigned int startLevel)
    : m_level(startLevel),
    m_value(0.0f)
{}

Capacity::Capacity(const Capacity& c)
    : m_level(c.m_level),
    m_value(c.m_value)
{}

Capacity& Capacity::operator=(const Capacity& c)
{
    if (&c != this)
    {
        m_level = c.m_level;
        m_value = c.m_value;
    }

    return *this;
}

Capacity::~Capacity()
{}

float Capacity::getValue() const
{
    return m_value;
}

unsigned int Capacity::getLevel() const
{
    return m_level;
}

void Capacity::setLevel(unsigned int level)
{
    m_level = level;
    recompute();
}

void Capacity::upgrade()
{
    ++m_level;
    recompute();
}

void Capacity::downgrade()
{
    --m_level;
    recompute();
}

void Capacity::init()
{
    recompute();
}