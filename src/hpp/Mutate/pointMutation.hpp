#ifndef EVO_POINTMUTATION_HPP
#define EVO_POINTMUTATION_HPP

#include <cmath>
#include "../std.hpp"

namespace Evo {
    namespace mutate {
        template<typename T, typename Number, typename Random>
        T point_draw(T individual, Number mutations, Random random) {
            if (mutations == static_cast<Number>(0))
                return individual;

            if (mutations > individual.size())
                mutations = individual.size();

            std::vector<Number> genes(mutations);
            Evo::reservoir_sampling_numbers(static_cast<Number>(0), static_cast<Number>(individual.size()), genes.begin(), mutations);

            for (auto& gene : genes) {
                auto iter = std::next(individual.begin(), gene);
                *iter = random(individual, iter);
            }

            return individual;
        }

        template<typename T, typename Predicate, typename Random>
        T point_loop(T individual, Predicate pred, Random random) {
            for (auto iter = individual.begin(); iter != individual.end(); std::advance(iter, 1))
                if (pred(individual, iter))
                    *iter = random(individual, iter);

            return individual;
        }
    }
}

#endif //EVO_POINTMUTATION_HPP
