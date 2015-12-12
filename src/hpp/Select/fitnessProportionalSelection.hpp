#ifndef FITNESSPROPORTIONALSELECTION_HPP
#define FITNESSPROPORTIONALSELECTION_HPP

#include "../std.hpp"

using std::vector;
using std::mt19937_64;
using std::uniform_real_distribution;
using std::accumulate;
using std::lower_bound;
using std::partial_sum;

namespace Evo {
	namespace Select {
		class FitnessProportional {
			private:
				mt19937_64 generator;					
				
			public:
				FitnessProportional() : generator(42) {}
				
				template<class Iter>
				vector<uint> operator()(Iter begin, Iter end, double number) {
					double total = static_cast<double>(accumulate(begin, end, 0.0));
					uniform_real_distribution<double> generate(0, total);
							
					vector<double> probs(end - begin);
					partial_sum(begin, end, probs.begin());
						
					vector<uint> chosen(number);
					for (auto& idx : chosen)
						idx = lower_bound(probs.begin(), probs.end(), generate(generator)) - probs.begin();
					
					return chosen;
				}
		};	
	}
}

#endif