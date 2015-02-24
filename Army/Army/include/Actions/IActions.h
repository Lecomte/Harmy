#ifndef _IACTIONS_H_
#define _IACTIONS_H_

#include <string>

class IAction
{
public:
    virtual ~IAction() {};
    virtual void execute() = 0;

protected:
    virtual std::string toString() const = 0;
};

#endif //_IACTIONS_H_