#ifndef _NOTHINGACTION_H_
#define _NOTHINGACTION_H_

#include "IActions.h"
#include "..\Unit.h"

class NothingAction : public IAction
{
public:
    NothingAction(unsigned int armyId, Unit& unit);
    ~NothingAction();

    virtual void execute();

protected:
    unsigned int m_unitArmyId;
    Unit& m_unit;

    virtual std::string toString() const;

private:
    NothingAction(const NothingAction&);
    NothingAction& operator=(const NothingAction&);
};

#endif //_NOTHINGACTION_H_