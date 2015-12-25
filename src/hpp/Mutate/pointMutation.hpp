#ifndef EVO_POINTMUTATION_HPP
#define EVO_POINTMUTATION_HPP

#include "../std.hpp"

namespace Evo {
    namespace mutate {
        template<typename T, typename Random>
        void point(T& individual, Random random) {
            std::uniform_int_distribution<uint> dist(0, individual.size() - 1);
            uint pos = dist(Evo::generator);

            typename T::iterator elem(individual.begin());
            std::advance(elem, pos);

            *elem = random(pos);
        }
    }
}

#endif //EVO_POINTMUTATION_HPP
