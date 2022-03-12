#pragma once

/* SPDX-License-Identifier: GPL-3.0-or-later */

#include <avnd/helpers/controls.hpp>

#include <map>

namespace avnd
{

template <typename T>
struct sample_accurate_values
{
  std::map<int, T> values;
};

template <typename T>
struct accurate
    : T
    , sample_accurate_values<std::decay_t<decltype(T::value)>>
{
};

}
