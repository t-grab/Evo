#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "std.hpp"

typedef std::vector<T*> Population<T>;
typedef void (*)(Population<T>&) Init_Func;

namespace Evo {
	void solve();
}

#endif