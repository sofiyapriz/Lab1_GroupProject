#pragma once
#include <functional>
#include <memory>
#include <stdexcept>
struct InputData {
    std::function<double(double)> f;
    double a;
    double b;
    size_t n;
};
struct Result {
    double integral_value;
    size_t evaluations_count;
};
std::unique_ptr<Result> calculateSimpson(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateTrapezoidal(std::shared_ptr<const InputData> data);