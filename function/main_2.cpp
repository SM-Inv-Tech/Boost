#include <iostream>

#include "boost/function.hpp"

void sum_avg(const int values[], int n, int &sum, float &avg)
{
    sum = 0;
    for (int i = 0; i != n; ++i)
    {
        sum += values[i];
    }
    avg = static_cast<float>(sum) / n;
}

int main(int argc, char **argv)
{
    boost::function<void(int *, int, int &, float &)> func = sum_avg;

    int values[5] = {1, 1, 2, 3, 5};
    int sum;
    float avg;
    func(values, 5, sum, avg);

    std::cout << "sum = " << sum << std::endl;
    std::cout << "avg = " << avg << std::endl;
    return 0;
}