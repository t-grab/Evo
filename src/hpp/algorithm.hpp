#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "std.hpp"
#include "population.hpp"
#include "termination.hpp"

#include <iostream>

namespace Evo {		
	template<class T, class TerminationCondition> 
	void solve(Population<T>& population, TerminationCondition should_terminate) {
		// INIT POPULATION
		population.init();
		
		// EVALUATE INDIVIDUAL in POPULATION
		int counter(0);
		while (!should_terminate(population)) {
			std::cout << counter++ << std::endl;
		// 		SELECT parents
		//		RECOMBINE pairs of parents		
		//		MUTATE offsprings
		//		EVALUATE offsprings
		// 		SELECT survivors
		//		
		//		LOGGING
		}
		
		// secure RESULT
		
		// return RESULT
	}
}

#endif