#pragma once
#ifndef _CAPACITY_H_
#define _CAPACITY_H_

class Capacity
{
public:
    /**
     * Constructors of Capacity
     */
    Capacity(unsigned int startLevel = 0);
    Capacity(const Capacity&);
    Capacity& operator=(const Capacity&);
    virtual ~Capacity();

    /**
     * Getter and setter of capacity value
     */
    float getValue() const;
    unsigned int getLevel() const ;
    
    //Recompute is call into this function
    virtual void setLevel(unsigned int level);

    /**
     * Upgrade and Downgrade a capacity
     */
    virtual void upgrade();
    virtual void downgrade();

    /**
     * Call init function for initial setup
     * implement this function is you want a special intialisation
     * (Special attribut, Health curLife == m_value)
     */
    virtual void init();

    /**
     * Recompute level value
     */
    virtual void recompute() = 0;

protected:
    unsigned int m_level;
    float m_value;
};

#endif //_CAPACITY_H_