#include "Capacity/ReloadCapacity.h"

ReloadCapacity::ReloadCapacity(unsigned int startLevel)
    : Capacity(startLevel),
    m_curReload(0.0f)
{}

ReloadCapacity::ReloadCapacity(const ReloadCapacity& r)
    : Capacity(r),
    m_curReload(r.m_curReload)
{}

ReloadCapacity& ReloadCapacity::operator=(const ReloadCapacity& r)
{
    if (&r != this)
    {
        Capacity::operator=(r);
        m_curReload = r.m_curReload;
    }

    return *this;
}

ReloadCapacity::~ReloadCapacity()
{}

void ReloadCapacity::init()
{
    Capacity::init();
    m_curReload = 0.0f;
}

void ReloadCapacity::recompute()
{
    m_value = 1000.0f / (static_cast<float>(m_level + 1));
}

float ReloadCapacity::getCurrentReload() const
{
    return m_curReload;
}

void ReloadCapacity::setCurrentReload(float max)
{
    m_curReload = max;

    if (m_curReload < 0.0f)
        m_curReload = 0.0f;

    else if (m_curReload > m_value)
        m_curReload = m_value;
}

void ReloadCapacity::updateValue()
{
    if (m_curReload - 1.0f >= 0.0f)
        --m_curReload;
}

void ReloadCapacity::upgrade()
{
    Capacity::upgrade();

    m_curReload = m_value;
}

void ReloadCapacity::downgrade()
{
    Capacity::downgrade();

    if (m_curReload > m_value)
        m_curReload = m_value;
}

void ReloadCapacity::setLevel(unsigned int level)
{
    Capacity::setLevel(level);

    m_curReload = m_value;
}