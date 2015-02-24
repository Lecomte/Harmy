#ifndef _SHOOTACTION_H_
#define _SHOOTACTION_H_

#include "IActions.h"
#include "..\Unit.h"

class ShootAction : public IAction
{
public:
    ShootAction(unsigned int launcherUnitArmyId, Unit& launcherUnit, unsigned int targetUnitArmyId, Unit& target, float damage);
    ~ShootAction();
    
    virtual void execute();
    

protected:
    unsigned int m_launcherArmyId;
    Unit& m_launcher;

    unsigned int m_targetArmyId;
    Unit& m_target;

    float m_damage;

    virtual std::string toString() const;
private:
    ShootAction(const ShootAction&);
    ShootAction& operator=(const ShootAction&);
};

#endif //_SHOOTACTION_H_