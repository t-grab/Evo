#ifndef EVO_ROULETTEWHEEL_H
#define EVO_ROULETTEWHEEL_H

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    // Value:  value_type -> (0;1]
    template<typename In, typename Out, typename Value, typename Clone>
    Out roulette_wheel_select(In first, In last, Out out, uint num, Value value, Clone clone) {
        if (num == 0)
            return out;

        typedef typename std::iterator_traits<In>::value_type value_type;
        typedef typename std::result_of<Value(value_type)>::type fitness_type;

        std::vector<fitness_type> partials(std::distance(first, last));
        Evo::partial_sum(first, last, partials.begin(), value);

        std::uniform_real_distribution<fitness_type> dist;

        while (num-- > 0) {
            uint idx = std::lower_bound(partials.begin(), partials.end(), dist(Evo::generator)) - partials.begin();
            In iter = first;

            std::advance(iter, idx);
            *out = clone(*iter);
            std::advance(out, 1);
        }

        return out;
    }
}

#endif //EVO_ROULETTEWHEEL_H
