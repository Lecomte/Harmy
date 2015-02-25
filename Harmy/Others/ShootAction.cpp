#include "ShootAction.h"


ShootAction::ShootAction(Unit& attacker, Unit& target, std::string myArmyCode, std::string opponentArmyCode) :attacker_(attacker), target_(target), attackerArmyCode(myArmyCode), targetArmyCode(opponentArmyCode)
{
}

void ShootAction::execute()
{
	target_.takeDamage(attacker_.damage_get().value_get());
	attacker_.firerate_get().reset_value();
	//Print shoot action
	std::cout << "L'unite : " << this->attacker_.UNIQ_ID_get() << " de l'armee " << this->attackerArmyCode 
		<< " attaque " << this->target_.UNIQ_ID_get()  << " de l'armee " << this->targetArmyCode << " qui a maintenant : " << target_.health_get().value_get() << "HP" << std::endl;
}

ShootAction::~ShootAction()
{
}