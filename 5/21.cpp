#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::string bword;

    while (std::cin >> word)
    {
        if (word == bword && isupper(word[0]))
        {
            std::cout << word << std::endl;
            break;
        }
        bword = word;
    }

    if (!std::cin)
    {
        std::cout << "No word starting with an uppercase letter was repeated."
                  << std::endl;
    }

    return 0;
}
