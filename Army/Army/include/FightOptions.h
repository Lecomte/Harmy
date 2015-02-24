#ifndef _FIGHTOPTIONS_H_
#define _FIGHTOPTIONS_H_

#include <vector>
#include<memory>

#include "Army.h"

/**
 *
 */
typedef struct BattleArmy
{
    /**
     * Shared pointeur to army
     */
    std::shared_ptr<Army> army;

    /**
     * Score of army
     * it use for choose best army
     */
    unsigned int score;

    /**
     * use for sort algorithm
     */
    bool operator<(const BattleArmy& b)
    {
        return score < b.score;
    }
}BattleArmy;

/**
 * FightOptions is a container of program configuration
 */
typedef struct FightOptions
{
    /**
     * Number of iteration
     */
    unsigned int I;
    
    /**
     * Max score for an Army
     */
    unsigned int T;

    /**
     * Number of army
     */
    unsigned int N;

    /**
     * number of unit for one army
     */
    unsigned int X;

    /**
     *
     */
    unsigned int Y;

    /**
     * Container of army
     */
    std::vector<BattleArmy> armyList;

    FightOptions()
        : I(0),
        T(0),
        N(0),
        X(0),
        Y(0)
    {}

    /**
     * if an attribut is equals of 0
     * options is not valid
     */
    bool isValid() const
    {
        return I != 0 && T != 0 && N != 0 && X != 0 && Y != 0;
    }

} FightOptions;

#endif //_FIGHTOPTIONS_H_