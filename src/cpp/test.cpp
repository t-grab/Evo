#include "../hpp/evo.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <functional>

int main() {	
	std::cout << "Evo" << std::endl;
		
	std::vector<double> fitness;
	fitness.push_back(1);
	fitness.push_back(2);
	fitness.push_back(1);
	fitness.push_back(500);
	fitness.push_back(3);
	fitness.push_back(4);
		
	vector<double> result(fitness.size());
	Evo::partial_sum(fitness.begin(), fitness.end(), result.begin(), [](double val) { return val; });
	
	for (auto& v : result)
		std::cout << v << std::endl;
	
	/*std::vector<double> result(fitness.size());
	Evo::partial_sum(fitness.begin(), fitness.end(), result.begin(), [](double val) { return val; });
	
	vector<uint> parent_indices = Evo::select::fitness_proportional(fitness.begin(), fitness.end(), 3);
	
	auto first = Evo::select::first(fitness.begin(), fitness.end());
	std::cout << "First " << first << std::endl;
	
	std::cout << "Amount: " << parent_indices.size() << std::endl;
	
	for (uint i : parent_indices)
		std::cout << i << std::endl;*/
	
	return 0;
}