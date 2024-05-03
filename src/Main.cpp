#include "Application.hpp"

int main()
{
    // Keep the whole thing wrapped in an exception-catching layer.
    try
    {
        Application app;

        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1; // failure
    }

    return 0;
}
