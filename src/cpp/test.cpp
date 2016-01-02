#include "../hpp/evo.hpp"

int main() {
    std::uniform_real_distribution<double> dist;
    double mutation_rate = 0.1;

    std::vector<int> vec = { 1, 4, 7, 3, 4, 2, 9, 5, 8, 6, 0, 2, 7, 7, 6 };
    std::vector<int> vec2 = { 1, 4, 7, 3, 4, 2, 9, 5, 8, 6, 0, 2, 7, 7, 6 };
    std::vector<int> res = Evo::mutate::point(vec, 0.1, [](uint pos) { return 10; });
    std::vector<int> res2 = Evo::mutate::point(vec2, [&]() { return dist(Evo::generator) < mutation_rate; },
                                               [](uint pos) { return 10; });

    for (auto& v : res)
        std::cout << v << " ";

    std::cout << std::endl;

    for (auto& v : res2)
        std::cout << v << " ";

	return 0;
}