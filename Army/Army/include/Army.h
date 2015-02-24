#ifndef _ARMY_H_
#define _ARMY_H_

#include <vector>
#include <atomic>

#include "Unit.h"

/**
 * Army class
 */
class Army
{
public:
    /**
     * Constructor of Army 
     */
    Army(unsigned int nUnit, unsigned int globalLevel);
    Army(const std::vector<Unit*>&);
    Army(const Army&);
    Army& operator=(const Army&);
    ~Army();

    /**
     * Getter of attributs of an Army
     */
    unsigned int getId() const;
    const std::vector<Unit*>& getUnitsList() const;
    std::vector<Unit*>& getUnitsList();
    Unit& getUnit(unsigned int id);
    unsigned int size() const;
    unsigned int getScore() const;
    unsigned int getGlobalLevel() const;

    /**
     * Return Nearest/Ferther Unit or Lower/Highest capacity 
     */
    Unit& getNearestUnit(const Point<>& p);
    Unit& getFartherUnit(const Point<>& p);
    Unit& getLowestUnit(unsigned int cap);
    Unit& getHighestUnit(unsigned int cap);
    
    /**
     * Delete all dead unit
     */
    void purge();

    /**
     * Mutate an percent of unit or replace by units by new untis
     */
    Army mutate() const;
    
    /**
     * Create new Army and set a percent of a army, a percent of b army and one croisement of one unit of a and b
     */
    Army operator *(const Army& a) const;

    /**
     * Return list of capacity unit and IA Code
     * Each line of string represent one unit
     */
    std::string toString() const;

    /* Set position of all unit with plus/minus random value */
    void setBaseposition(const Point<>& pos);

protected:
    unsigned int m_id;
    std::vector<Unit*> m_units;
    unsigned int m_globalLevel;

    static std::atomic<unsigned int> m_instanceId;

    /**
     * delete all units
     */
    void purgeUnits();

    /**
     * calculate global level of Army
     */
    void computeGlobalLevel();
};

#endif //#endif //