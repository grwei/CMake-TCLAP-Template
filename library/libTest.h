#ifndef __libTest
#define __libTest
#include <iostream>
#include <vector>

// seperate compilation test:
// Only the int and double versions are spanned in libTest.cpp.
template <class T>
T sumOfVector(const std::vector<T> &vec);

// The function used to span some versions of the template above.
double sumOfDouble(const std::vector<double> &vec);

#endif // __libTest
