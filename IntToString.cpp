#include <iostream>
#include <sstream>
#include "IntToString.h"

/**
 * @brief   IntToString translating the int value to the string.
 * @param   value
 * @return  the string of the input value
 *
 * @author  sheng
 * @version 0.1  [build the function] [2013/12/18] [sheng]
 */


std::string IntToString(int value)
{
    std::ostringstream convert;
    convert << value;
    return convert.str();
}
