////////////////////////////////////////////////////////////////////////
/// \file      main_1.cpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年09月24日, Sat, 10:46
/// \version   1.0
/// \brief
#include <iostream>

#include "boost/function.hpp"

class int_div
{
public:
    float operator()(int x, int y) const
    {
        return static_cast<float>(x) / y;
    }
};

int main(int argc, char **argv)
{
    boost::function<float(int, int)> func = int_div();
    std::cout << func(3, 6) << std::endl;

    return 0;
}