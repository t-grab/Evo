#ifndef EVO_TOURNAMENTSELECTION_HPP
#define EVO_TOURNAMENTSELECTION_HPP

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    namespace select {
        template<typename In, typename Out, typename Value, typename Clone>
        Out tournament(In first, In last, Out out, uint num, uint k, Value value, Clone clone) {
            typedef typename std::iterator_traits<In>::value_type value_type;

            while (num-- > 0) {
                std::vector<value_type> competitors(k);
                Evo::sample_with_replacement(first, last, competitors.begin(), k, clone);
                *out = *std::max_element(competitors.begin(), competitors.end(),
                                         [&](const value_type& one, const value_type& two) {
                                             return value(one) < value(two);
                                         }
                );

                std::advance(out, 1);
            }

            return out;
        }
    }
}

#endif //EVO_TOURNAMENTSELECTION_HPP
