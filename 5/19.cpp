#include <iostream>
#include <string>

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    do
    {
        if (str1 == str2)
        {
           std::cout << "The two strings are equal." << std::endl;
        }
        else if (str1 < str2)
        {
           std::cout << "The first string is less than the second."
                     << std::endl;
        }
        else
        {
           std::cout << "The second string is less than the first."
                     << std::endl;
        }
    }
    while (std::cin >> str1 >> str2);

    return 0;
}
