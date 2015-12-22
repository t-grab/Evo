#ifndef EVO_ROULETTEWHEEL_H
#define EVO_ROULETTEWHEEL_H

#include "../std.hpp"
#include "../algorithm.hpp"

namespace Evo {
    namespace select {
        template<typename T>
        class Roulette_Wheel {
        public:
            Roulette_Wheel() : dist() {}

            T operator()() {
                return dist(Evo::generator);
            }
        private:
            std::uniform_real_distribution<T> dist;
        };
    }
}

#endif //EVO_ROULETTEWHEEL_H
