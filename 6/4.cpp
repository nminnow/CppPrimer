#include <iostream>

int fact()
{
    int val;
    std::cout << "Enter a number: ";
    std::cin >> val;
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int main()
{
    std::cout << "The factorial of the number is " << fact() << std::endl;
    return 0;
}
