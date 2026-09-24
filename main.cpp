#include <iostream>
#include "shared_types.h"
int main() {
    auto data = std::make_shared<const InputData>(
        InputData{ [](double x) { return x * x; }, 0.0, 10.0, 1000 }
    );
    auto resultB = calculateTrapezoidal(data);
    auto [valB, evalB] = *resultB;
    std::cout << "Trapezoidal: " << valB << "\n";
    auto resultA = calculateSimpson(data);
    auto [valA, evalA] = *resultA;
    std::cout << "Simpson: " << valA << "\n";
    return 0;
}