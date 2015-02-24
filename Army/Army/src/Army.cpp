#include "Army.h"

#include <cassert>
#include <limits>
#include <algorithm>

#include "Constants.h"
#include "Utils.h"

std::atomic<unsigned int> Army::m_instanceId = 0;

Army::Army(unsigned int nUnit, unsigned int globalLevel)
    : m_id(++m_instanceId),
    m_globalLevel(0),
    m_units(nUnit, nullptr)
{
    if (nUnit > 0)
    {
        unsigned int levelUnit = globalLevel / nUnit;

        m_globalLevel = globalLevel;

        for (unsigned int i = 0; i < nUnit; ++i)
            m_units[i] = new Unit(levelUnit);
    }
}

Army::Army(const std::vector<Unit*>& unitList)
    : m_id(++m_instanceId),
    m_globalLevel(0),
    m_units(unitList.size(), nullptr)
{
    unsigned int i = 0;

    for (auto unit : unitList)
    {
        m_globalLevel += unit->getGlobalLevel();
        
        m_units[i] = new Unit(*unit);
        ++i;
    }
}

Army::Army(const Army& a)
    : m_units(a.m_units.size(), nullptr),
    m_id(a.m_id),
    m_globalLevel(a.m_globalLevel)
{
    unsigned int unitSize = a.size();

    for (unsigned int i = 0; i < unitSize; ++i)
        m_units[i] = new Unit(*a.m_units[i]);
}

Army& Army::operator=(const Army& a)
{
    if (this != &a)
    {
        m_id = a.m_id;

        purgeUnits();

        m_globalLevel = a.m_globalLevel;

        for (auto unit : a.m_units)
            m_units.push_back(new Unit(*unit));
    }

    return *this;
}

Army::~Army()
{
    purgeUnits();
}

unsigned int Army::getId() const
{
    return m_id;
}

const std::vector<Unit*>& Army::getUnitsList() const
{
    return m_units;
}

std::vector<Unit*>& Army::getUnitsList()
{
    return m_units;
}

Unit& Army::getUnit(unsigned int id)
{
    assert(id < m_units.size());

    return *(m_units[id]);
}

unsigned int Army::size() const
{
    return m_units.size();
}

Unit& Army::getNearestUnit(const Point<>& p)
{
    assert(m_units.size() > 0);

    unsigned int minMagnitudeIndex = 0;
    float minMagnitude = (p - m_units[0]->getPosition()).sqrMagnitude();
    unsigned int unitSize = m_units.size();

    for (unsigned int i = 1; i < unitSize; ++i)
    {
        float curMagnitude = (p - m_units[minMagnitudeIndex]->getPosition()).sqrMagnitude();

        if (curMagnitude < minMagnitude)
        {
            minMagnitudeIndex = i;
            minMagnitude = curMagnitude;
        }
    }

    return *(m_units[minMagnitudeIndex]);
}

Unit& Army::getFartherUnit(const Point<>& p)
{
    assert(m_units.size() > 0);

    unsigned int maxMagnitudeIndex = 0;
    float maxMagnitude = (p - m_units[0]->getPosition()).sqrMagnitude();
    unsigned int unitSize = m_units.size();

    for (unsigned int i = 1; i < unitSize; ++i)
    {
        float curMagnitude = (p - m_units[maxMagnitudeIndex]->getPosition()).sqrMagnitude();

        if (curMagnitude > maxMagnitude)
        {
            maxMagnitudeIndex = i;
            maxMagnitude = curMagnitude;
        }
    }

    return *(m_units[maxMagnitudeIndex]);
}

Unit& Army::getLowestUnit(unsigned int cap)
{
    assert(m_units.size() > 0 && cap < NUMBEROFCAPACITY);

    unsigned int minCapacityValueIndex = 0;
    float minCapacityValue = (*(m_units[0]))[cap].getValue();
    unsigned int unitSize = m_units.size();

    for (unsigned int i = 1; i < unitSize; ++i)
    {
        float curValue = (*(m_units[i]))[cap].getValue();

        if (curValue < minCapacityValue)
        {
            minCapacityValueIndex = i;
            minCapacityValue = curValue;
        }
    }

    return *(m_units[minCapacityValueIndex]);
}

Unit& Army::getHighestUnit(unsigned int cap)
{
    assert(m_units.size() > 0 && cap < NUMBEROFCAPACITY);

    unsigned int maxCapacityValueIndex = 0;
    float maxCapacityValue = (*(m_units[0]))[cap].getValue();
    unsigned int unitSize = m_units.size();

    for (unsigned int i = 1; i < unitSize; ++i)
    {
        float curValue = (*(m_units[i]))[cap].getValue();

        if (curValue > maxCapacityValue)
        {
            maxCapacityValueIndex = i;
            maxCapacityValue = curValue;
        }
    }

    return *(m_units[maxCapacityValueIndex]);
}

unsigned int Army::getScore() const
{
    return m_units.size();
}

unsigned int Army::getGlobalLevel() const
{
    return m_globalLevel;
}

void Army::purge()
{
    auto unitIterator = m_units.begin();

    while (unitIterator != m_units.end())
    {
        if ((*unitIterator)->isAlive())
            ++unitIterator;

        else
        {
            m_globalLevel -= (*unitIterator)->getGlobalLevel();

            delete *unitIterator;
            unitIterator = m_units.erase(unitIterator);
        }
    }
}

Army Army::mutate() const
{
    Army copy(*this);

    unsigned int unitModif = rand() % copy.size();

    if (rand() % 2 == 0)
    {
        unsigned int globalLevelPerUnit = m_globalLevel / copy.size();

        //Random new units
        for (unsigned int i = 0; i < unitModif; ++i)
        {
            Unit& unit = copy.getUnit(rand() % copy.size());
            copy.m_globalLevel -= unit.getGlobalLevel();
            copy.m_globalLevel += globalLevelPerUnit;

            unit = Unit(globalLevelPerUnit);
        }
    }
    else
    {
        //Mutate units
        for (unsigned int i = 0; i < unitModif; ++i)
        {
            Unit& chooseUnit = copy.getUnit(rand() % copy.size());
            chooseUnit = chooseUnit.mutate();
        }
    }

    return copy;
}

Army Army::operator *(const Army& a) const
{
    std::vector<Unit*> tmp;
    Army copy(tmp);

    unsigned int selfCopyCount = rand() % m_units.size();
    unsigned int aCopyCount = rand() % a.m_units.size();

    for (unsigned int i = 0; i < selfCopyCount; ++i)
        copy.m_units.push_back(new Unit(*(m_units[rand() % m_units.size()])));

    for (unsigned int i = 0; i < aCopyCount; ++i)
        copy.m_units.push_back(new Unit(*(a.m_units[rand() % a.m_units.size()])));

    copy.m_units.push_back(new Unit(*(m_units[rand() % m_units.size()]) * (*(a.m_units[rand() % a.m_units.size()]))));
    
    copy.computeGlobalLevel();

    return copy;
}

std::string Army::toString() const
{
    std::string res;

    for (auto unit : m_units)
    {
        res += unit->toString() + std::string("\n");
    }

    return res;
}

void Army::setBaseposition(const Point<>& pos)
{
    for (auto unit : m_units)
    {
        float xSign = rand() % 2 == 0 ? -1.0f : 1.0f;
        float ySign = rand() % 2 != 0 ? -1.0f : 1.0f;

        unit->setPosition(
            Point<>(
                utils::clamp<float>(pos.getX() + (xSign * (rand() % static_cast<int>((BOARDWIDTH * 0.1f)))), 0, BOARDWIDTH),
                utils::clamp<float>(pos.getY() + (ySign * (rand() % static_cast<int>((BOARDHEIGHT * 0.1f)))), 0, BOARDHEIGHT)
                )
            );
    }
}

void Army::purgeUnits()
{
    for (auto unit : m_units)
        delete unit;

    m_units.clear();
    m_globalLevel = 0;
}

void Army::computeGlobalLevel()
{
    m_globalLevel = 0;

    for (auto unit : m_units)
        m_globalLevel += unit->getGlobalLevel();
}