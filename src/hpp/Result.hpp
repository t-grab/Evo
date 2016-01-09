#ifndef EVO_RESULT_HPP
#define EVO_RESULT_HPP

#include "std.hpp"
#include <unordered_set>
#include <iostream>
#include <string>

namespace Evo {
    template<typename T, typename M, typename D>
    class Result {
    public:
        Result() : max_fitness(), max_vals(), avg_vals(), diversity(), num_solutions(), solutions() {}

        template<typename In>
        void add_generation(M max, M avg, In first, In last) {
            max_vals.push_back(max);
            avg_vals.push_back(avg);
            num_solutions.push_back(std::distance(first, last));

            if (max >= max_fitness) {
                if (max > max_fitness)
                    solutions.clear();
                solutions.insert(first, last);
            }
        }

        template<typename In>
        void add_generation(M max, M avg, D div, In first, In last) {
            add_generation(max, avg, first, last);
            diversity.push_back(div);
        }

        std::unordered_set<T>& fittest() {
            return solutions;
        }

        void print(std::ostream& out = std::cout, const std::string& sep = "\t", bool verbose = false) const {
            out << "Generation" << sep << "Max" << sep << "Average" << sep << "#Fittest";
            if (diversity.size() < max_vals.size()) {
                out << std::endl;
                for (uint i(0U); i < max_vals.size(); ++i)
                    out << i << sep << max_vals[i] << sep << avg_vals[i] << sep << num_solutions[i] << std::endl;
            } else {
                out << sep << "Diversity" << std::endl;
                for (uint i(0U); i < max_vals.size(); ++i)
                    out << i << sep << max_vals[i] << sep << avg_vals[i] << sep << num_solutions[i] << sep << diversity[i] << std::endl;
            }

            if (verbose)
                for (auto& solution : solutions)
                    out << solution << std::endl;
        }
    private:
        M max_fitness;

        std::vector<M> max_vals;
        std::vector<M> avg_vals;
        std::vector<D> diversity;
        std::vector<unsigned int> num_solutions;
        std::unordered_set<T> solutions;
    };
}

#endif //EVO_RESULT_HPP
