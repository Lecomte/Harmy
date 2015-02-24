#include <limits>
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <fstream>

#include "Utils.h"
#include "Army.h"
#include "IA.h"
#include "FightOptions.h"

void diffUnitList(const std::vector<Unit*>& unitList, const std::vector<Unit*>& already, std::vector<Unit*>& diff)
{
    diff.clear();

    for (auto unit : unitList)
    {
        if (std::find(already.begin(), already.end(), unit) == already.end())
            diff.push_back(unit);
    }
}

void fightArmy(Army& a, Army& b)
{
    unsigned int turn = 0;
    IA ia;

    if (DEBUGMODE)
        std::cout << "Start fight Army " << std::to_string(a.getId()) << " versus Army " << std::to_string(b.getId()) << std::endl;

    while (a.size() > 0 && b.size() > 0)
    {
        if (DEBUGMODE)
            std::cout << "============= Tour " << ++turn << " =================" << std::endl;

        unsigned int aUnitsSize(a.size());
        unsigned int bUnitsSize(b.size());
        unsigned int unitsNumber = aUnitsSize + bUnitsSize;

        //Create a copy of unitList foreach army
        std::vector<Unit*> aAlreadyUnit;
        std::vector<Unit*> bAlreadyUnit;
        std::vector<Unit*> aDiffUnit;
        std::vector<Unit*> bDiffUnit;

        for (unsigned int i = 0; i < unitsNumber; ++i)
        {
            Unit* unit(nullptr);
            unsigned int randomUnitIndex = 0;
            
            Army* unitArmy(nullptr);
            Army* opposing(nullptr);

            /* Get unit availiable for a and b army */
            diffUnitList(a.getUnitsList(), aAlreadyUnit, aDiffUnit);
            diffUnitList(b.getUnitsList(), bAlreadyUnit, bDiffUnit);
            
            std::vector<Unit*>* randomArmy(nullptr);
            
            if (rand() % 2 == 0 && aDiffUnit.size() > 0)
            {
                //Take unit into A army
                unitArmy = &a;
                opposing = &b;

                randomArmy = &aDiffUnit;
            }
            else
            {
                //Take unit into B army
                if (bDiffUnit.size() > 0)
                {
                    unitArmy = &b;
                    opposing = &a;

                    randomArmy = &bDiffUnit;
                }
                else
                {
                    //B haven't unit take into a army
                    unitArmy = &a;
                    opposing = &b;

                    randomArmy = &aDiffUnit;
                }
            }

            //Get random unit
            randomUnitIndex = rand() % randomArmy->size();

            unit = (*randomArmy)[randomUnitIndex];
            randomArmy->erase(randomArmy->begin() + randomUnitIndex);

            //Get IA Action
            std::shared_ptr<IAction> action = ia(*unit, *unitArmy, *opposing);
            action->execute();

            a.purge();
            b.purge();

            if (a.size() == 0 || b.size() == 0)
                break;
        }

        for (auto unit : a.getUnitsList())
            unit->refresh();

        for (auto unit : b.getUnitsList())
            unit->refresh();
    }

    std::string idA(std::to_string(a.getId()));
    std::string idB(std::to_string(b.getId()));

    if (DEBUGMODE)
        std::cout << "Score Armee " << idA << " : " << a.size() << ", Score Armee " << idB << " : " << b.size() << std::endl;

    if (DEBUGMODE)
    {
        if (a.size() > 0)
        {
            std::cout << "Armee " << idA << " gagne la bataille ! " << std::endl;
        }
        else
        {
            std::cout << "Armee " << idB << " gagne la bataille ! " << std::endl;
        }
    }
}

bool descendingSortArmyList(const BattleArmy& a, const BattleArmy& b)
{
    return b.score < a.score;
}

/* Save into file army a*/
void saveArmy(const Army& a)
{
    std::cout << "Save best army into file" << std::endl;

    std::string fileName("army_");

    fileName += std::to_string(a.size()) + std::string("_") + std::to_string(a.getGlobalLevel()) + std::string(".save");

    std::ofstream output(fileName);

    if (!output.is_open())
    {
        std::cout << "Can't open file : " << fileName << " !" << std::endl;
        return;
    }

    output << a.toString();

    output.close();
    std::cout << "end of save best army into file" << std::endl;
}

void findBestArmy(FightOptions& fight)
{
    std::cout << "Start find best army algorithm !" << std::endl;

    fight.armyList.clear();

    /* Create N Army */
    for (unsigned int i = 0; i < fight.N; ++i)
    {
        BattleArmy battleArmy;
        battleArmy.army = std::shared_ptr<Army>(new Army(fight.X, fight.Y));
        battleArmy.score = 0;

        fight.armyList.push_back(battleArmy);
    }

    /* I Iteration */
    for (unsigned int i = 0; i < fight.I; ++i)
    {
        unsigned int armyCount = fight.armyList.size();

        //Change by armyList.size
        for (unsigned int armyIterator = 0; armyIterator < armyCount; ++armyIterator)
        {
            for (unsigned int versusIterator = 0; versusIterator < armyCount; ++versusIterator)
            {
                if (versusIterator == armyIterator)
                    continue;

                Army curArmy(*(fight.armyList[armyIterator].army));
                Army versusArmy(*(fight.armyList[versusIterator].army));
                Point<> armyPos;
                
                unsigned int middleBoardX = static_cast<int>(BOARDWIDTH / 2.0f);
                unsigned int middleBoardY = static_cast<int>(BOARDHEIGHT / 2.0f);
                /* Set position of army on the board */

                if (rand() % 2 == 0)
                {
                    //curArmy -> bottom, versus -> Top
                    armyPos.setY( static_cast<float>(rand() % middleBoardY + middleBoardY ));
                }
                else
                {
                    armyPos.setY( static_cast<float>(rand() % middleBoardY ));
                }

                if (rand() % 2 == 0)
                {
                    //curArmy -> left, versusArmy -> right
                    armyPos.setX(static_cast<float>(rand() % middleBoardX));
                }
                else
                {
                    armyPos.setX(static_cast<float>(rand() % middleBoardX + middleBoardX));
                }

                curArmy.setBaseposition(armyPos);
                versusArmy.setBaseposition(-armyPos);

                fightArmy(curArmy, versusArmy);
                fight.armyList[armyIterator].score += curArmy.getScore();
                fight.armyList[versusIterator].score += versusArmy.getScore();
            }
        }
        
        std::sort(fight.armyList.begin(), fight.armyList.end(), descendingSortArmyList);

        if (fight.armyList.front().score >= fight.T)
            break;


        unsigned int newArmyFactor = static_cast<unsigned int>(std::ceil(static_cast<float>(fight.N) * 0.1f));
        
        /* N*0.1 army stay */
        std::vector<BattleArmy> newArmy;
        BattleArmy newBattleArmy;

        //TODO CHECK THIS PART

        /* 10 percent of best */
        for (unsigned int createNewBattleArmyIterator = 0; createNewBattleArmyIterator < newArmyFactor; ++createNewBattleArmyIterator)
        {
            newBattleArmy.army = std::shared_ptr<Army>(new Army(*(fight.armyList[createNewBattleArmyIterator].army)));
            newBattleArmy.score = 0;
            newArmy.push_back(newBattleArmy);
        }

        newArmyFactor = static_cast<unsigned int>(std::ceil(static_cast<float>(fight.N) * 0.3f));

        /* 30 percent of cross best and random */
        for (unsigned int createNewBattleArmyIterator = 0; createNewBattleArmyIterator < newArmyFactor; ++createNewBattleArmyIterator)
        {
            Army crossArmy((*(fight.armyList[createNewBattleArmyIterator].army)) * (*(fight.armyList[rand() % fight.N].army)));

            newBattleArmy.army = std::shared_ptr<Army>(new Army(crossArmy));
            newBattleArmy.score = 0;
            newArmy.push_back(newBattleArmy);
        }

        /* 30 percent of mutate best */
        for (unsigned int createNewBattleArmyIterator = 0; createNewBattleArmyIterator < newArmyFactor; ++createNewBattleArmyIterator)
        {
            Army mutateArmy = fight.armyList[createNewBattleArmyIterator].army->mutate();

            newBattleArmy.army = std::shared_ptr<Army>(new Army(mutateArmy));
            newBattleArmy.score = 0;
            newArmy.push_back(newBattleArmy);
        }

        /* 30 percent of random */
        for (unsigned int createNewBattleArmyIterator = 0; createNewBattleArmyIterator < newArmyFactor; ++createNewBattleArmyIterator)
        {
            newBattleArmy.army = std::shared_ptr<Army>(new Army(fight.X, fight.Y));
            newBattleArmy.score = 0;
            newArmy.push_back(newBattleArmy);
        }

        /* Copy army list */
        fight.armyList = newArmy;
    }

    std::cout << "End of find best army" << std::endl;

    /* Save best army */
    saveArmy(*fight.armyList.front().army);
}

void argParam(int argc, char** argv, FightOptions& fight)
{
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "-I") == 0)
        {
            ++i;
            fight.I = static_cast<unsigned int>(strtoul(argv[i], nullptr, 10));
        }
        else if (strcmp(argv[i], "-T") == 0)
        {
            ++i;
            fight.T = static_cast<unsigned int>(strtoul(argv[i], nullptr, 10));
        }
        else if (strcmp(argv[i], "-N") == 0)
        {
            ++i;
            fight.N = static_cast<unsigned int>(strtoul(argv[i], nullptr, 10));
        }
        else if (strcmp(argv[i], "-X") == 0)
        {
            ++i;
            fight.X = static_cast<unsigned int>(strtoul(argv[i], nullptr, 10));
        }
        else if (strcmp(argv[i], "-Y") == 0)
        {
            ++i;
            fight.Y = static_cast<unsigned int>(strtoul(argv[i], nullptr, 10));
        }
        else if (strcmp(argv[i], "-d") == 0)
            DEBUGMODE = true;
    }
}

void standarInputParameter(FightOptions& fight)
{
    
    std::cout << "Entrer la valeur pour le parametre I" << std::endl;
    utils::readIStream(std::cin, fight.I);

    std::cout << std::endl <<  "Entrer la valeur pour le parametre T" << std::endl;
    utils::readIStream(std::cin, fight.T);

    std::cout << std::endl << "Entrer la valeur pour le parametre N" << std::endl;
    utils::readIStream(std::cin, fight.N);

    std::cout << std::endl << "Entrer la valeur pour le parametre X" << std::endl;
    utils::readIStream(std::cin, fight.X);

    std::cout << std::endl << "Entrer la valeur pour le parametre Y" << std::endl;
    utils::readIStream(std::cin, fight.Y);

    std::cout << std::endl << "Souhaitez vous afficher les logs ? (0/1)" << std::endl;
    utils::readIStream(std::cin, fight.Y);
}

int main(int argc, char** argv)
{
    srand(NULL);

    FightOptions fightOptions;

    if (argc > 1)
        argParam(argc - 1, &(argv[1]), fightOptions);

    if (!fightOptions.isValid())
    {
        standarInputParameter(fightOptions);
    }
    else
        findBestArmy(fightOptions);

    return 0;
}