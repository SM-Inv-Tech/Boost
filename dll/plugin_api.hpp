////////////////////////////////////////////////////////////////////////
/// \file      plugin_api.hpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年09月24日, Sat, 10:36
/// \version   1.0
/// \brief
#ifndef BOOST_PLUGIN_API_HPP
#define BOOST_PLUGIN_API_HPP

#include <string>

#include "boost/enable_shared_from_this.hpp"

class plugin_api : public boost::enable_shared_from_this<plugin_api>
{
public:
    virtual ~plugin_api() = default;

public:
    virtual std::string name() const = 0;

    virtual float calculate(float x, float y) = 0;

    virtual boost::shared_ptr<plugin_api> on_ticks() = 0;
};

#endif // BOOST_PLUGIN_API_HPP

