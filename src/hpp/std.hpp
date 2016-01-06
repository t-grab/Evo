#ifndef STD_HPP
#define STD_HPP

#include <type_traits>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <random>
typedef unsigned int uint;
typedef long unsigned int luint;

namespace Evo {
	static std::mt19937_64 generator(42);
}

#endif