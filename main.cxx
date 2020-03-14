#include "AuthorInformation.h"
#include "libTest.h"
#include "tclap/CmdLine.h" // TCLAP
#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
        // Define the command line object.
        TCLAP::CmdLine cmd("Command description message", ' ', "0.1", true);

        // Define some arguments.
        TCLAP::SwitchArg AuthorInformationDisplaySwitch("", "author", "display author information", cmd, false);

        // Parse the argv array.
        cmd.parse(argc, argv);

        if (AuthorInformationDisplaySwitch.getValue())
        {
            AuthorInformation<>()("Author Information: ");
        }
    }
    catch (const TCLAP::ArgException &e)
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }

    // seperate compilation test:
    // Only the int and double versions are spanned in libTest.cpp.
    std::cout << sumOfVector(std::vector<int>{1, 2, 3, 4, 5}) << '\n';
    std::cout << sumOfVector(std::vector<double>{1, 2, 3, 4, 5}) << '\n';
    
    // no span, link error: undefine reference to...
    std::cout << sumOfVector(std::vector<float>{1, 2, 3, 4, 5}) << '\n';
    std::cout << std::endl;

    return 0;
}
