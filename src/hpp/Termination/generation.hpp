#ifndef TERMINATION_HPP
#define TERMINATION_HPP

#include "../std.hpp"

namespace Termination {
	class Generation {
		public:
			Generation(uint maxGen) : max(maxGen), current(0U) {}
		
			uint generation() const {
				return current;
			}
		
			template<class T>
			bool operator()() {
				return current++ >= max;
			}
		private:	
			uint max;
			uint current;
	};
}
#endif