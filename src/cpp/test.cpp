#include "../hpp/evo.hpp"
#include <iostream>
#include <array>

int main() {	
	std::cout << "Evo" << std::endl;
	
	std::vector<double> fitness;
	fitness.push_back(1);
	fitness.push_back(2);
	fitness.push_back(1);
	fitness.push_back(500);
	fitness.push_back(3);
	fitness.push_back(4);
	
	Evo::Select::FitnessProportional select;
	vector<uint> idx(select(fitness.begin(), fitness.end(), 3));
	
	std::cout << "Amount: " << idx.size() << std::endl;
	
	for (uint i : idx)
		std::cout << i << std::endl;
	
	return 0;
}