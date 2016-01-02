#ifndef EVO_POINTMUTATION_HPP
#define EVO_POINTMUTATION_HPP

#include <cmath>
#include "../std.hpp"

namespace Evo {
    namespace mutate {
        template<typename T, typename Predicate, typename Random>
        T point(T individual, Predicate pred, Random random) {
            int i = 0;
            for (auto& var : individual) {
                if (pred())
                    var = random(i);
                ++i;
            }

            return individual;
        }

        template<typename T, typename Random>
        T point(T individual, double rate, Random random) {
            typedef typename std::result_of<decltype(&T::size)(T)>::type idx_type;

            std::exponential_distribution<double> dist(1 / (rate * individual.size()));
            idx_type mutations = static_cast<idx_type>(round(dist(Evo::generator)));
            if (mutations > individual.size())
                mutations = individual.size();

            std::vector<idx_type> genes(mutations);
            Evo::reservoir_sampling_numbers(static_cast<idx_type>(0), individual.size(), genes.begin(), mutations);

            for (auto& gene : genes)
                *std::next(individual.begin(), gene) = random(gene);

            return individual;
        }
    }
}

#endif //EVO_POINTMUTATION_HPP
