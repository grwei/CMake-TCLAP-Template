#include "libTest.h"

// seperate compilation test
template <class T>
T sumOfVector(const std::vector<T> &vec)
{
    T sum{0};
    for (auto elem : vec)
        sum += elem;

    return sum;
}

double sumOfDouble(const std::vector<double> &vec)
{
    // Span the int and double version of template sumOfVector,
    // so that the above versions can be used in main.cxx.
    
    auto sum = sumOfVector(std::vector<int>{1, 2, 3});
    return sumOfVector(vec);
}
