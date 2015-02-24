#include "Actions\ShootAction.h"

#include <iostream>

ShootAction::ShootAction(unsigned int launcherUnitArmyId, Unit& launcherUnit, unsigned int targetUnitArmyId, Unit& target, float damage)
    : m_launcherArmyId(launcherUnitArmyId),
    m_launcher(launcherUnit),
    m_targetArmyId(targetUnitArmyId),
    m_target(target),
    m_damage(damage)
{}

ShootAction::~ShootAction()
{}

void ShootAction::execute()
{
    if (DEBUGMODE)
        std::cout << toString() << std::endl;

    m_target.takeDamage(m_damage);
}

ShootAction::ShootAction(const ShootAction& a)
    : m_launcherArmyId(a.m_launcherArmyId),
    m_launcher(a.m_launcher),
    m_targetArmyId(a.m_targetArmyId),
    m_target(a.m_target),
    m_damage(a.m_damage)
{}

ShootAction& ShootAction::operator=(const ShootAction& s)
{
    if (this != &s)
    {
        m_launcher = s.m_launcher;
        m_launcherArmyId = s.m_launcherArmyId;
        m_target = s.m_target;
        m_targetArmyId = s.m_targetArmyId;
        m_damage = s.m_damage;
    }

    return *this;
}

std::string ShootAction::toString() const
{
    std::string res("Unite ");

    res += std::to_string(m_launcher.getId()) + std::string(" (Armee ") + std::to_string(m_launcherArmyId) + std::string(")");
    res += " attaque ";
    res += std::string("Unite ") + std::to_string(m_target.getId()) + std::string(" (Armee ") + std::to_string(m_targetArmyId) + std::string(") qui n'a plus que ");
    res += std::to_string(static_cast<int>(m_target.getHealth().getCurLife() - m_damage)) + std::string(" HP");

    return res;
}