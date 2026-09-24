#include "shared_types.h"
std::unique_ptr<Result> calculateSimpson(std::shared_ptr<const InputData> data) {
    if (data->n % 2 != 0) {
        throw std::invalid_argument("Для методу Сімпсона n має бути парним.");
    }
    auto result = std::make_unique<Result>();
    double h = (data->b - data->a) / data->n;
    double sum = data->f(data->a) + data->f(data->b);
    result->evaluations_count = 2;
    for (size_t i = 1; i < data->n; ++i) {
        double x = data->a + i * h;
        sum += data->f(x) * ((i % 2 == 0) ? 2.0 : 4.0);
        result->evaluations_count++;
    }
    result->integral_value = sum * h / 3.0;
    return result;
}