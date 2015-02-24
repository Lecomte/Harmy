#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <sstream>
#include <algorithm>

#include "Constants.h"

namespace utils
{
    //Macro for disable unused function parameter
#define ARGUNUSED(x) ((void)x)

    
    //Clamp function
    template<typename T>
    inline T clamp(T x, T min, T max)
    {
        return std::min(std::max(min, x), max);
    }

    //Dynamic cast SRC pointer to DEST pointer
    template<typename SRC, typename DEST>
    inline DEST* dynamicCaster(SRC* from)
    {
        DEST* to = dynamic_cast<DEST*>(from);

        if (to == nullptr && DEBUGMODE)
        {
            std::cout << "Can't dynamic_cast !" << std::endl;
        }

        return to;
    }

    //Dynamic cast const SRC pointer to const DEST pointer
    template<typename SRC, typename DEST>
    inline const DEST* dynamicCaster(const SRC* from)
    {
        const DEST* to = dynamic_cast<const DEST*>(from);

        if (to == nullptr && DEBUGMODE)
        {
            std::cout << "Can't dynamic_cast !" << std::endl;
        }

        return to;
    }

    /**
     * readIStream is use for get secure input user
     * clearBuffer is use for clear an input stream (when in have an error)
     */
    void readIStream(std::istream& in, unsigned int& value);
    void clearBuffer(std::istream& in);
}
#endif //_UTILS_H_