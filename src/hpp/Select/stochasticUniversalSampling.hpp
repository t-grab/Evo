#ifndef EVO_STOCHASTICUNIVERSALSAMPLING_HPP
#define EVO_STOCHASTICUNIVERSALSAMPLING_HPP

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    namespace select {
        template<typename T>
        class SUS {
        public:
            SUS(uint num) : step_size(1.0 / num), value() {
                std::uniform_real_distribution<T> dist(0, step_size);
                value = dist(Evo::generator);
            }

            T operator()() {
                T temp = value;
                value += step_size;

                return temp;
            }
        private:
            T step_size;
            T value;
        };
    }
}

#endif //EVO_STOCHASTICUNIVERSALSAMPLING_HPP
