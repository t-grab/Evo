#ifndef EVO_TOURNAMENTSELECTION_HPP
#define EVO_TOURNAMENTSELECTION_HPP

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    namespace select {
        template<typename In, typename Out, typename Value>
        Out tournament(In first, In last, Out out, uint num, uint k, Value value) {
            typedef typename std::iterator_traits<In>::value_type value_type;

            while (num-- > 0) {
                std::vector<value_type> competitors(k);
                Evo::sample_with_replacement(first, last, competitors.begin(), k);
                *out = *std::max_element(competitors.begin(), competitors.end(),
                                         [&](const value_type& one, const value_type& two) {
                                             return value(one) < value(two);
                                         }
                );

                std::advance(out, 1);
            }

            return out;
        }

        template<typename Value>
        class Tournament {
        public:
            Tournament(uint num, uint k, Value value) : num_elements(num), tournament_size(k), value_function(value) {}

            template<typename In, typename Out>
            inline Out operator()(In first, In last, Out out) {
                return tournament(first, last, out, num_elements, tournament_size, value_function);
            }
        private:
            uint num_elements;
            uint tournament_size;
            Value value_function;
        };
    }
}

#endif //EVO_TOURNAMENTSELECTION_HPP
