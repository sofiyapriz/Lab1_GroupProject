#include "shared_types.h"

std::unique_ptr<Result> calculateTrapezoidal(std::shared_ptr<const InputData> data) {
    auto result = std::make_unique<Result>();
    double h = (data->b - data->a) / data->n;
    double sum = (data->f(data->a) + data->f(data->b)) / 2.0;
    result->evaluations_count = 2;

    for (size_t i = 1; i < data->n; ++i) {
        sum += data->f(data->a + i * h);
        result->evaluations_count++;
    }
    result->integral_value = sum * h;
    return result;
}