#ifndef _UNIT_H_
#define _UNIT_H_

#include <vector>
#include <atomic>

#include "Constants.h"
#include "Point.h"
#include "Capacity\AllCapacity.h"

/**
 * Unit class represent an Unit
 *
 */

class Unit
{
public:
    /**
     * Constructor and operator =
     */
    Unit(unsigned int globalLevel);
    Unit(const char codeIA[IACODELENGHT], unsigned int speedLevel, unsigned int healthLevel, unsigned int armorLevel, unsigned int regenLevel, unsigned int damageLevel, unsigned int rangeLevel, unsigned int reloadLevel);
    Unit(const Unit&);
    Unit& operator=(const Unit&);
    ~Unit();

    /**
     * Setup all of capacity of an unit with parameter
     */
    void setupCapacity(unsigned int speedLevel = 0, unsigned int healthLevel = 0, unsigned int armorLevel = 0, unsigned int regenLevel = 0, unsigned int damageLevel = 0, unsigned int rangeLevel = 0, unsigned int reloadLevel = 0);

    /**
     * Getter of attributs
     */
    unsigned int getId() const;
    unsigned int getLevel() const;
    Point<> getPosition() const;
    Point<>& getPosition();
    unsigned int getGlobalLevel() const;
    const std::vector<Capacity*>& getCapacity() const;
    std::vector<Capacity*>& getCapacity();
    char* getIACode();
    const char* getIACode() const;

    /**
     * Getter of specifique capacity
     */
    const SpeedCapacity& getSpeed() const;
    const HealthCapacity& getHealth() const;
    const ArmorCapacity& getArmor() const;
    const RegenCapacity& getRegen() const;
    const DamageCapacity& getDamage() const;
    const RangeCapacity& getRange() const;
    const ReloadCapacity& getReload() const;

    SpeedCapacity& getSpeed();
    HealthCapacity& getHealth();
    ArmorCapacity& getArmor();
    RegenCapacity& getRegen();
    DamageCapacity& getDamage();
    RangeCapacity& getRange();
    ReloadCapacity& getReload();

    Capacity& operator[](unsigned int capacity);

    /**
     * Refresh an unit
     * up healt and down reload
     */
    void refresh();

    /**
     * Setter of position
     */
    void setPosition(const Point<>&);

    /**
     * Check if unit can shoot
     * set reload time to maximum reload if unit can shoot
     */
    bool shoot();

    /**
     * Return life > 0
     */
    bool isAlive() const;
    
    /**
     * Take damage reduce value with armor value and remove newValue to life of unit
     */
    void takeDamage(float value);

    /**
     * Return new Unit
     * Downgrade random capacity and upgrade another random capacity
     * number of downgrade and upgrafe is random and don't modify globalLevel
     */
    Unit mutate() const;

    /**
     * Return new Unit
     * The level of each capacity of new unit is between level of 2 unit
     */
    Unit operator*(const Unit& u) const;

    /**
     * Return string with unit capacity level and IACode
     */
    std::string toString() const;

    /* Call init function into all capacity */
    void initCapacity();

protected:
    unsigned int m_id;
    unsigned int m_level;
    Point<> m_position;
    char m_codeIA[IACODELENGHT];

    std::vector<Capacity*> m_capacity;

    static std::atomic<unsigned int> m_instanceNumber;

    /**
     * Delete capacity
     */
    void cleanCapacity();
};

#endif //_UNIT_H_