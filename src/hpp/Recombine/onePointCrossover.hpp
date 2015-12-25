#ifndef EVO_ONEPOINTCROSSOVER_HPP
#define EVO_ONEPOINTCROSSOVER_HPP

#include "../std.hpp"

#include <tuple>

namespace Evo {
    namespace recombine {
        template<typename T>
        std::tuple<T, T> one_point_crossover(T first, T second) {
            std::uniform_int_distribution<uint> dist(1, first.size() - 1);
            uint split = dist(Evo::generator);

            typedef typename T::iterator iterator;
            iterator first_split = first.begin();
            iterator second_split = second.begin();
            std::advance(first_split, split);
            std::advance(second_split, split);

            std::vector<typename std::iterator_traits<iterator>::value_type> buffer(second_split, second.end());
            std::copy(first_split, first.end(), second_split);
            std::copy(buffer.begin(), buffer.end(), first_split);

            return std::make_tuple(first, second);
        }
    }
}

#endif //EVO_ONEPOINTCROSSOVER_HPP
