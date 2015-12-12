#ifndef FITNESSPROPORTIONALSELECTION_HPP
#define FITNESSPROPORTIONALSELECTION_HPP

#include "../std.hpp"

using std::vector;
using std::uniform_real_distribution;
using std::accumulate;
using std::lower_bound;
using std::partial_sum;

namespace Evo {
	namespace Select {
		template<class Iter, class T, class Getter>
		vector<T> extract_variable(Iter begin, Iter end, Getter get) {
			vector<T> result;
			while (begin != end)
				result.push_back(get(*begin++));
			return result;
		}
		
		template<class Iter>
		vector<uint> fitness_proportional(Iter begin, Iter end, double number) {
			double total = static_cast<double>(accumulate(begin, end, 0.0));
			uniform_real_distribution<double> generate(0, total);
					
			vector<double> probs(end - begin);
			partial_sum(begin, end, probs.begin());
				
			vector<uint> chosen(number);
			for (auto& idx : chosen)
				idx = lower_bound(probs.begin(), probs.end(), generate(Evo::generator)) - probs.begin();
			
			return chosen;
		}
		
		template<class Iter, class Getter>
		vector<uint> fitness_proportional(Iter begin, Iter end, double number, Getter get) {
			vector<double> fitness_values(extract_variable<double>(begin, end, get));
			return fitness_proportional(fitness_values.begin(), fitness_values.end(), number);
		}		
	}
}

#endif