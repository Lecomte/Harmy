#include "IA.h"

#include "Utils.h"
#include "Actions\NothingAction.h"
#include "Actions\MoveAction.h"
#include "Actions\ShootAction.h"

IA::IA()
{}

IA::~IA()
{
}

std::shared_ptr<IAction> IA::operator()(Unit& unit, Army& a, Army& opposingArmy)
{
    IAction* action;
    Unit* target = nullptr;

    ARGUNUSED(a);

    if (unit.getReload().getCurrentReload() > 0.0f)
    {
        if (unit.getIACode()[1] == 'D')
        {
            if (unit.getIACode()[0] == 'H')
                target = &(opposingArmy.getFartherUnit(unit.getPosition()));
            else
                target = &(opposingArmy.getNearestUnit(unit.getPosition()));
        }
        else
        {
            unsigned int capId = unit.getIACode()[1] - '0';

            if (capId < NUMBEROFCAPACITY)
            {
                if (unit.getIACode()[0] == 'H')
                    target = &(opposingArmy.getHighestUnit(capId));

                else
                    target = &(opposingArmy.getLowestUnit(capId));
            }
        }

        if (target == nullptr)
            action = new NothingAction(a.getId(), unit);

        else
        {
            Point<> direction(target->getPosition() - unit.getPosition());

            if (direction.magnitude() < unit.getRange().getValue())
            {
                //FIRE !!!
                action = new ShootAction(a.getId(), unit, opposingArmy.getId(), *target, unit.getDamage().getValue());
            }
            else
            {
                //MOVE !!!
                action = new MoveAction(a.getId(), unit, direction);
            }
        }
    }
    else
    {
        if (opposingArmy.size() > 0)
        {
            const std::vector<Unit*> units(opposingArmy.getUnitsList());

            Point<> centerOfMass(0.0f, 0.0f);

            for (auto unit : units)
                centerOfMass += unit->getPosition();

            centerOfMass /= static_cast<float>(opposingArmy.size());

            //RUN AWAY !!!
            action = new MoveAction(a.getId(), unit, -(centerOfMass - unit.getPosition()));
        }
        else
        {
            action = new NothingAction(a.getId(), unit);
        }
    }
    
    return std::shared_ptr<IAction>(action);
}

IA::IA(const IA& a)
{
    ARGUNUSED(a);
}

IA& IA::operator=(const IA& a)
{
    ARGUNUSED(a);

    return *this;
}