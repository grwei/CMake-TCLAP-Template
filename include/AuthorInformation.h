#ifndef __AuthorInformation
#define __AuthorInformation

#include <iostream>
#include <string>

template <class T = std::string>
class AuthorInformation
{
private:
    std::string AuthorName{"Author Name: Wei Guorui\n"};
    std::string EmailAddr{"Email: weiguorui@sjtu.edu.cn\n"};
    std::string StuNumber{"Student Number: 516021910080\n"};

public:
    T Tobj;
    T display(std::ostream &os) const
    {
        os << AuthorName << StuNumber << EmailAddr;
        return T();
    }
    T operator()(std::string desc = "Description message: ") const
    {
        std::cout << '\n'
                  << desc << '\n'
                  << *this << std::endl;
        return Tobj;
    }
};

std::ostream &operator<<(std::ostream &os, const AuthorInformation<> &obj)
{
    obj.display(os);
    os << '\n';
    return os;
}

#endif // __AuthorInformation
