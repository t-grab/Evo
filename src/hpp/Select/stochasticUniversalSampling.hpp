#ifndef EVO_STOCHASTICUNIVERSALSAMPLING_HPP
#define EVO_STOCHASTICUNIVERSALSAMPLING_HPP

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    template<typename In, typename Out, typename Value, typename Clone>
    Out sus_select(In first, In last, Out out, uint num, Value value, Clone clone) {
        if (num == 0)
            return out;

        typedef typename std::iterator_traits<In>::value_type value_type;
        typedef typename std::result_of<Value(value_type)>::type fitness_type;

        std::vector<fitness_type> partials(std::distance(first, last));
        Evo::partial_sum(first, last, partials.begin(), value);

        double step_size = 1.0 / num;
        std::uniform_real_distribution<fitness_type> dist(0, step_size);
        double val = dist(Evo::generator);

        while (num-- > 0) {
            uint idx = std::lower_bound(partials.begin(), partials.end(), val) - partials.begin();
            In iter = first;

            std::advance(iter, idx);
            *out = clone(*iter);
            std::advance(out, 1);

            val += step_size;
        }

        return out;
    }
}

#endif //EVO_STOCHASTICUNIVERSALSAMPLING_HPP
