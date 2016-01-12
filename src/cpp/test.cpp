#include "../hpp/evo.hpp"

int main() {
	std::vector<double> test = { 0.5, 0.5 };
	for (uint i = 0U; i < 1000000; ++i) {
		test = Evo::mutate::creep(test, 0.01, std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
		//std::cout << test[0] << ", " << test[1] << std::endl;
	}

	std::cout << test[0] << ", " << test[1] << std::endl;

	return 0;
}