#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1 = {0, 1, 1, 2}; // for example
    std::vector<int> vec2 = {0, 1, 1, 2, 3, 5, 8};

    auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
    bool prefix = true;

    for (decltype(size) v = 0; v != size; ++v)
    {
        if (vec1[v] != vec2[v])
        {
            prefix = false;
        }
    }

    if (prefix)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}
