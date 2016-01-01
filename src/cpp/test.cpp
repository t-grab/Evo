#include "../hpp/evo.hpp"

int main() {
    std::vector<int> test = { 1, 2, 3 };

    Evo::Result<int, double> res;
    res.add_generation(5.0, 5.0, test.begin(), test.end());

    res.print(std::cout, " ", true);

	return 0;
}