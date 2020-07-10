#include <iostream>
#include <exception>

int main()
{
    int i1, i2;

    while (std::cin >> i1 >> i2)
    {
        try
        {
            if (i2 == 0)
            {
                throw std::runtime_error("Division by zero is not allowed.");
            }
            std::cout << i1 << " / " << i2 << " = " << i1 / i2 << std::endl;
        }
        catch (std::runtime_error err)
        {
            std::cerr << err.what() << "\nTry again? [y]es, [n]o: ";
            char c;
            if (!(std::cin >> c) || c == 'n')
            {
                break;
            }
        }
    }

    return 0;
}
