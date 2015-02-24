#ifndef _IA_H_
#define _IA_H_

#include<memory>
#include <string>
#include "Unit.h"
#include "Army.h"
#include "Actions\IActions.h"

/**
 * IA class
 */
class IA
{
public:
    IA();    
    ~IA();

    /**
     * Take a decision for unit behavior
     * Return an IAction, call execute function of IAction for apply action into target (unit or enemy unit)
     * Delete IAction
     */
    virtual std::shared_ptr<IAction> operator()(Unit&, Army&, Army&);

private:
    IA(const IA&);
    IA& operator=(const IA&);
};

#endif //_IA_H_