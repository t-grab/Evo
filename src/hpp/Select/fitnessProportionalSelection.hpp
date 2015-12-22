#ifndef FITNESSPROPORTIONALSELECTION_HPP
#define FITNESSPROPORTIONALSELECTION_HPP

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
	namespace select {
        // Value:  value_type -> (0;1]
        template<typename In, typename Out, typename Value, typename Clone, typename Provider>
		Out fitness_proportional(In first, In last, Out out, uint num, Value value, Clone clone, Provider val) {
            if (num == 0)
                return out;

            typedef typename std::iterator_traits<In>::value_type value_type;
            typedef typename std::result_of<Value(value_type)>::type fitness_type;

            std::vector<fitness_type> partials(std::distance(first, last));
            Evo::partial_sum(first, last, partials.begin(), value);

            while (num-- > 0) {
                uint idx = std::lower_bound(partials.begin(), partials.end(), val()) - partials.begin();
                In iter = first;

                std::advance(iter, idx);
                *out = clone(*iter);
                std::advance(out, 1);
            }

            return out;
        }
	}
}

#endif