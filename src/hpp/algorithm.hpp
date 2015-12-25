#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "std.hpp"
#include <iterator>
#include <functional>

namespace Evo {		
	template<typename In, typename Out, typename Value,
	 		 typename BinOp = std::plus<typename std::result_of<Value(typename std::iterator_traits<In>::value_type)>::type>>
	Out partial_sum(In first, In last, Out out, Value value, BinOp op = BinOp()) {
		if (first == last) return out;
		
		typedef typename std::iterator_traits<In>::value_type value_type;
		typename std::result_of<BinOp(value_type, value_type)>::type acc = value(*first); 
		
        *out = acc;
		while (++first != last) {
			acc = op(acc, value(*first));
			*++out = acc;
		}
		
		return ++out;
	}	

	template<typename In, typename Out>
	Out sample_with_replacement(In first, In last, Out out, uint k) {
        std::uniform_int_distribution<uint> dist(0, std::distance(first, last) - 1);
        while (k-- > 0) {
            In iter = first;
            std::advance(iter, dist(Evo::generator));

            *out = *iter;
            std::advance(out, 1);
        }

        return out;
    }


	// Standard Genetic Algorithm
		// INIT POPULATION	
		// EVALUATE INDIVIDUAL in POPULATION
		// while not TERMINATIONCONDITION
		// do
		// 		SELECT parents
		//		RECOMBINE pairs of parents		
		//		MUTATE offsprings
		//		EVALUATE offsprings
		// 		SELECT survivors
		// end do
		// return RESULT
		
		// secure RESULT
		
		// return RESULT
}

#endif