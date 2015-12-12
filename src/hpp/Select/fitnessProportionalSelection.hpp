#ifndef FITNESSPROPORTIONALSELECTION_HPP
#define FITNESSPROPORTIONALSELECTION_HPP

#include "../std.hpp"

using std::vector;
using std::mt19937_64;
using std::uniform_real_distribution;
using std::accumulate;
using std::lower_bound;

namespace Evo {
	namespace Select {
		class FitnessProportional {
			private:
				mt19937_64 generator;
				uniform_real_distribution<double> generate;
									
				vector<uint> choose(const vector<double>& probs, uint number) {
					vector<uint> chosen(number);
					for (uint i(0U); i < number; ++i)
						chosen[i] = lower_bound(probs.begin(), probs.end(), generate(generator)) - probs.begin();
					
					return chosen;
				}					
				
			public:
				FitnessProportional() : generate(0.0, 1.0), generator(100) {}
				
				template<class Iter>
				vector<uint> operator()(Iter begin, Iter end, double number) {
					double total(static_cast<double>(accumulate(begin, end, 0.0)));
							
					vector<double> probs(end - begin);
					probs[0] = *begin / total;
					for (uint i(1U); i < probs.size(); ++i)
						probs[i] = probs[i - 1] + *(begin + i) / total;
						
					return choose(probs, number);
				}
				
				template<class T, class Iter, class Fitness>
				vector<uint> operator()(Iter begin, Iter end, double number, Fitness fitness) {
					double total(static_cast<double>(accumulate(begin, end, 0.0, [&](double curr, const T& individual) {
						return curr + fitness(individual);
					})));
					
					vector<double> probs(end - begin);
					probs[0] = fitness(*begin) / total;
					for (uint i(1U); i < probs.size(); ++i)
						probs[i] = probs[i - 1] + fitness(*(begin + i)) / total;
					
					return choose(probs, number);
				}
		};   	
	}
}

#endif