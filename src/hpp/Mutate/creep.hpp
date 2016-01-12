//
// Created by Tobias on 12.01.2016.
//

#ifndef EVO_CREEP_HPP
#define EVO_CREEP_HPP

namespace Evo {
    namespace mutate {
        template<typename T, typename StepSize, typename Number>
        T creep(T individual, StepSize step_size, Number lower_bound, Number upper_bound) {
            std::normal_distribution<Number> normal(static_cast<Number>(0), static_cast<Number>(step_size));

            for (auto& gene : individual) {
                gene += normal(generator);

                if (gene < lower_bound)
                    gene = lower_bound;
                if (gene > upper_bound)
                    gene = upper_bound;
            }

            return individual;
        }
    }
}

#endif //EVO_CREEP_HPP
