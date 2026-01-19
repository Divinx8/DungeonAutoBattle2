#pragma once
#include <random>

class Random {
public:
    static Random& instance() {
        static Random r;
        return r;
    }

    int intInRange(int a, int b) { // inclusif
        std::uniform_int_distribution<int> dist(a, b);
        return dist(gen);
    }

    double real01() {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(gen);
    }

private:
    Random() : gen(std::random_device{}()) {}
    std::mt19937 gen;
};
