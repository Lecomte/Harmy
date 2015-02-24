#include "Actions\MoveAction.h"

#include <iostream>

#include "Utils.h"
MoveAction::MoveAction(unsigned int armyId, Unit& unit, const Point<>& direction)
    : m_unitArmyId(armyId),
    m_unit(unit),
    m_direction(direction)
{
}

MoveAction::~MoveAction()
{}

void MoveAction::execute()
{
    if (DEBUGMODE)
        std::cout << toString() << std::endl;

    Point<> newPos(m_unit.getPosition() + (m_direction.normalise() * m_unit.getSpeed().getValue()));
    
    newPos.setX(utils::clamp<float>(newPos.getX(), 0, BOARDWIDTH));
    newPos.setY(utils::clamp<float>(newPos.getY(), 0, BOARDHEIGHT));

    m_unit.setPosition(newPos);
}

MoveAction::MoveAction(const MoveAction& ma)
    : m_unit(ma.m_unit)
{}

MoveAction& MoveAction::operator=(const MoveAction& a)
{
    if (this != &a)
    {
        m_unit = a.m_unit;
        m_unitArmyId = a.m_unitArmyId;
        m_direction = a.m_direction;
    }

    return *this;
}

std::string MoveAction::toString() const
{
    std::string res("Unitee ");

    res += std::to_string(m_unit.getId()) + std::string(" (Armee ") + std::to_string(m_unitArmyId) + std::string(") bouge en position");
    res += (m_unit.getPosition() + m_direction.normalise()).toString();

    return res;
}