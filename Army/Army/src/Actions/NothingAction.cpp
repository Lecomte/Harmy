#include "Actions\NothingAction.h"

#include "Utils.h"

NothingAction::NothingAction(unsigned int armyId, Unit& unit)
    : m_unitArmyId(armyId),
    m_unit(unit)
{}

NothingAction::~NothingAction()
{}

void NothingAction::execute()
{
    if (DEBUGMODE)
        std::cout << toString() << std::endl;
}

NothingAction::NothingAction(const NothingAction& n)
    : m_unitArmyId(n.m_unitArmyId),
    m_unit(n.m_unit)
{
}

NothingAction& NothingAction::operator=(const NothingAction& n)
{
    if (this != &n)
    {
        m_unit = n.m_unit;
        m_unitArmyId = n.m_unitArmyId;
    }

    return *this;
}

std::string NothingAction::toString() const
{
    return std::string("Unitee ") + std::to_string(m_unit.getId()) + std::string(" (Armee ") + std::to_string(m_unitArmyId) + std::string(") ne fait rien");
}