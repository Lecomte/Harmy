#include "Capacity/HealthCapacity.h"

#include "Utils.h"

HealthCapacity::HealthCapacity(unsigned int startLevel)
    : Capacity(startLevel),
    m_curLife(0)
{}

HealthCapacity::HealthCapacity(const HealthCapacity& h)
    : Capacity(h),
    m_curLife(h.m_curLife)
{}

HealthCapacity& HealthCapacity::operator=(const HealthCapacity& h)
{
    if (&h != this)
    {
        Capacity::operator=(h);

        m_curLife = h.m_curLife;
    }

    return *this;
}

HealthCapacity::~HealthCapacity()
{}

void HealthCapacity::init()
{
    Capacity::init();
    m_curLife = m_value;
}

void HealthCapacity::recompute()
{
    m_value = static_cast<float>((1 + m_level)) * 10.0f;
}

float HealthCapacity::getCurLife() const
{
    return m_curLife;
}

void HealthCapacity::setCurLife(float life)
{
    if (life > m_value)
        m_curLife = m_value;
    
    else if (life < 0.0f)
        m_curLife = 0.0f;
    
    else
        m_curLife = life;
}

void HealthCapacity::addLife(float life)
{
    if (life < 0.0f)
        return;

    double newLife = static_cast<double>(m_curLife) + static_cast<double>(life);
    
    newLife = utils::clamp<double>(newLife, 0.0, static_cast<double>(m_value));

    setCurLife(static_cast<float>(newLife));
}

void HealthCapacity::removeLife(float life)
{
    if (life < 0.0f)
        return;

    double newLife = static_cast<double>(m_curLife) - static_cast<double>(life);

    newLife = utils::clamp<double>(newLife, 0.0, static_cast<double>(m_value));

    setCurLife(static_cast<float>(newLife));
}

void HealthCapacity::upgrade()
{
    Capacity::upgrade();

    m_curLife = m_value;
}

void HealthCapacity::downgrade()
{
    Capacity::downgrade();

    if (m_curLife > m_value)
        m_curLife = m_value;
}

void HealthCapacity::setLevel(unsigned int level)
{
    Capacity::setLevel(level);

    m_curLife = m_value;
}