#ifndef _MOVEACTION_H_
#define _MOVEACTION_H_

#include "IActions.h"
#include "..\Unit.h"

class MoveAction : public IAction
{
public:
    MoveAction(unsigned int armyId, Unit& unit, const Point<>& direction);
    ~MoveAction();

    virtual void execute();

protected:
    unsigned int m_unitArmyId;
    Unit& m_unit;
    Point<> m_direction;

    virtual std::string toString() const;

private:
    MoveAction(const MoveAction&);
    MoveAction& operator=(const MoveAction&);
};

#endif //_MOVEACTION_H_