#include <cassert>
#include <algorithm>

#include "Unit.h"
#include "Utils.h"
#include "Constants.h"

//TODO Remplacer constructeur Unit par une factory

std::atomic<unsigned int> Unit::m_instanceNumber = 0;

Unit::Unit(unsigned int globalLevel)
    : m_id(++m_instanceNumber),
    m_level(globalLevel),
    m_position()
{
    m_codeIA[0] = FIRSTCODEIA[std::rand() % SIZEOFFIRSTCODEIA];
    m_codeIA[1] = SECONDCODEIA[std::rand() % SIZEOFSECONDCODEIA];

    setupCapacity();
    
    if (globalLevel > 0)
    {
        unsigned int numberOfCapacity = m_capacity.size();

        do
        {
            unsigned int randomCap = 0;

            randomCap = rand() % numberOfCapacity;
            m_capacity[randomCap]->upgrade();

            --globalLevel;
        } while (globalLevel > 0);
    }
}

Unit::Unit(const char codeIA[IACODELENGHT], unsigned int speedLevel, unsigned int healthLevel, unsigned int armorLevel, unsigned int regenLevel, unsigned int damageLevel, unsigned int rangeLevel, unsigned int reloadLevel)
    : m_id(++m_instanceNumber),
    m_level(speedLevel + healthLevel + armorLevel + regenLevel + damageLevel + rangeLevel + reloadLevel),
    m_position()
{
    memcpy(m_codeIA, codeIA, IACODELENGHT * sizeof(char));

    setupCapacity(speedLevel, healthLevel, armorLevel, regenLevel, damageLevel, rangeLevel, reloadLevel);
    initCapacity();
}

Unit::Unit(const Unit& u)
    : m_id(u.m_id),
    m_level(u.m_level),
    m_position(u.m_position)
{

    memcpy(m_codeIA, u.m_codeIA, IACODELENGHT * sizeof(char));

    m_capacity.push_back(new SpeedCapacity(u.getSpeed()));
    m_capacity.push_back(new HealthCapacity(u.getHealth()));
    m_capacity.push_back(new ArmorCapacity(u.getArmor()));
    m_capacity.push_back(new RegenCapacity(u.getRegen()));
    m_capacity.push_back(new DamageCapacity(u.getDamage()));
    m_capacity.push_back(new RangeCapacity(u.getRange()));
    m_capacity.push_back(new ReloadCapacity(u.getReload()));

    initCapacity();
}

Unit& Unit::operator = (const Unit& u)
{
    if (this != &u)
    {
        m_id = u.m_id;

        m_level = u.m_level;
        m_position = u.m_position;

        memcpy(m_codeIA, u.m_codeIA, IACODELENGHT * sizeof(char));

        getSpeed()  = u.getSpeed();
        getHealth() = u.getHealth();
        getArmor()  = u.getArmor();
        getRegen()  = u.getRegen();
        getDamage() = u.getDamage();
        getRange()  = u.getRange();
        getReload() = u.getReload();
    }

    return *this;
}

Unit::~Unit()
{
    cleanCapacity();
}

void Unit::cleanCapacity()
{
    for (auto capacity : m_capacity)
        delete capacity;

    m_capacity.clear();
}

void Unit::setupCapacity(unsigned int speedLevel, unsigned int healthLevel, unsigned int armorLevel, unsigned int regenLevel, unsigned int damageLevel, unsigned int rangeLevel, unsigned int reloadLevel)
{
    cleanCapacity();

    m_capacity.push_back(new SpeedCapacity(speedLevel));
    m_capacity.push_back(new HealthCapacity(healthLevel));
    m_capacity.push_back(new ArmorCapacity(armorLevel));
    m_capacity.push_back(new RegenCapacity(regenLevel));
    m_capacity.push_back(new DamageCapacity(damageLevel));
    m_capacity.push_back(new RangeCapacity(rangeLevel));
    m_capacity.push_back(new ReloadCapacity(reloadLevel));

    for (auto cap : m_capacity)
    {
        cap->init();
    }
}

const std::vector<Capacity*>& Unit::getCapacity() const
{
    return m_capacity;
}

std::vector<Capacity*>& Unit::getCapacity()
{
    return m_capacity;
}

Point<> Unit::getPosition() const
{
    return m_position;
}

Point<>& Unit::getPosition()
{
    return m_position;
}

//Check store global level
unsigned int Unit::getGlobalLevel() const
{
    unsigned int globalLevel = 0;

    for (auto cap : m_capacity)
        globalLevel += cap->getLevel();

    return globalLevel;
}

unsigned int Unit::getId() const
{
    return m_id;
}

unsigned int Unit::getLevel() const
{
    return m_level;
}

const SpeedCapacity& Unit::getSpeed() const
{
    const SpeedCapacity* speed = utils::dynamicCaster<Capacity, SpeedCapacity>(m_capacity[0]);

    return *speed;
}

const HealthCapacity& Unit::getHealth() const
{
    const HealthCapacity* health = utils::dynamicCaster<Capacity, HealthCapacity>(m_capacity[1]);

    return *health;
}

const ArmorCapacity& Unit::getArmor() const
{
    const ArmorCapacity* armor = utils::dynamicCaster<Capacity, ArmorCapacity>(m_capacity[2]);

    return *armor;
}

const RegenCapacity& Unit::getRegen() const
{
    const RegenCapacity* regen = utils::dynamicCaster<Capacity, RegenCapacity>(m_capacity[3]);

    return *regen;
}

const DamageCapacity& Unit::getDamage() const
{
    const DamageCapacity* damage = utils::dynamicCaster<Capacity, DamageCapacity>(m_capacity[4]);

    return *damage;
}

const RangeCapacity& Unit::getRange() const
{
    const RangeCapacity* range = utils::dynamicCaster<Capacity, RangeCapacity>(m_capacity[5]);

    return *range;
}

const ReloadCapacity& Unit::getReload() const
{
    const ReloadCapacity* reload = utils::dynamicCaster<Capacity, ReloadCapacity>(m_capacity[6]);

    return *reload;
}

SpeedCapacity& Unit::getSpeed()
{
    SpeedCapacity* speed = utils::dynamicCaster<Capacity, SpeedCapacity>(m_capacity[0]);

    return *speed;
}

HealthCapacity& Unit::getHealth()
{
    HealthCapacity* health = utils::dynamicCaster<Capacity, HealthCapacity>(m_capacity[1]);

    return *health;
}

ArmorCapacity& Unit::getArmor()
{
    ArmorCapacity* armor = utils::dynamicCaster<Capacity, ArmorCapacity>(m_capacity[2]);

    return *armor;
}

RegenCapacity& Unit::getRegen()
{
    RegenCapacity* regen = utils::dynamicCaster<Capacity, RegenCapacity>(m_capacity[3]);

    return *regen;
}

DamageCapacity& Unit::getDamage()
{
    DamageCapacity* damage = utils::dynamicCaster<Capacity, DamageCapacity>(m_capacity[4]);

    return *damage;
}

RangeCapacity& Unit::getRange()
{
    RangeCapacity* range = utils::dynamicCaster<Capacity, RangeCapacity>(m_capacity[5]);

    return *range;
}

ReloadCapacity& Unit::getReload()
{
    ReloadCapacity* reload = utils::dynamicCaster<Capacity, ReloadCapacity>(m_capacity[6]);

    return *reload;
}

Capacity& Unit::operator[](unsigned int capacity)
{
    assert(capacity < m_capacity.size() - 1);

    return *(m_capacity[capacity]);
}

void Unit::refresh()
{
    HealthCapacity& life = getHealth();
    RegenCapacity& regen = getRegen();
    ReloadCapacity& reload = getReload();

    life.addLife(regen.getValue());

    float curReload = reload.getCurrentReload();
    reload.setCurrentReload( --curReload );
}

void Unit::setPosition(const Point<>& p)
{
    m_position = p;
}

bool Unit::shoot()
{
    ReloadCapacity& reload = getReload();

    if (reload.getCurrentReload() == 0.0)
    {
        reload.setCurrentReload(reload.getValue());
        return true;
    }

    return false;
}

bool Unit::isAlive() const
{
    return getHealth().getCurLife() > 0.0f;
}

void Unit::takeDamage(float value)
{
    getHealth().removeLife(value - getArmor().getValue());
}

char* Unit::getIACode()
{
    return m_codeIA;
}

const char* Unit::getIACode() const
{
    return m_codeIA;
}

Unit Unit::mutate() const
{
    Unit copy(*this);

    std::vector<Capacity*> canDownCap(copy.m_capacity.size());

    unsigned int i = 0;
    for (auto cap : copy.m_capacity)
    {
        if (cap->getLevel() > 0)
            canDownCap[i++] = cap;
    }
        

    unsigned int randomCapIndex = rand() % canDownCap.size();
    Capacity* randomCap(canDownCap[randomCapIndex]);
    unsigned int curLevel = randomCap->getLevel();
    unsigned int downLevel = rand() % curLevel;

    randomCap->setLevel(curLevel - downLevel);

    Capacity* upCap(nullptr);

    do
    {
        upCap = copy.m_capacity[rand() % copy.m_capacity.size()];

        if (upCap == randomCap)
            upCap = nullptr;

    } while (upCap == nullptr);

    
    upCap->setLevel(upCap->getLevel() + downLevel);

    return copy;
}

Unit Unit::operator*(const Unit& u) const
{
    Unit copy(
        (rand() % 2 == 0 ? m_codeIA : u.m_codeIA),
        0, 0, 0, 0, 0, 0, 0
        );

	//Choose a random level between two units
	unsigned int maxLevel = std::max(this->getLevel(), u.getLevel());
	unsigned int minLevel = std::min(this->getLevel(), u.getLevel());

    unsigned int delta = maxLevel - minLevel;
    unsigned int globalLevel = 0;

    if (delta == 0)
    {
        globalLevel = maxLevel;
    }
    else
    {
        globalLevel = rand() % (maxLevel - minLevel) + minLevel;
    }

	copy.m_level = globalLevel;

	do
	{
        unsigned int indexLevel(rand() % NUMBEROFCAPACITY); // Choose a random capacity
        unsigned int maxCurrentLevel(std::max(m_capacity[indexLevel]->getLevel(), u.m_capacity[indexLevel]->getLevel())); // I could use max instead of this
        unsigned int currentLevel(copy.m_capacity[indexLevel]->getLevel());

		if (currentLevel < maxCurrentLevel)
		{
			copy.m_capacity[indexLevel]->upgrade();
			globalLevel--;
		}
	} while (globalLevel > 0);

    return copy;
}

std::string Unit::toString() const
{
    std::string res;

    for (auto cap : m_capacity)
        res += std::to_string(cap->getLevel()) + std::string(" ");

    res += m_codeIA[0];
    res += m_codeIA[1];

    return res;
}

void Unit::initCapacity()
{
    for (auto cap : m_capacity)
        cap->init();
}