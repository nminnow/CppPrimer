#include <iostream>
#include <iterator>

int main()
{
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // range-based for loops
    for (int (& p)[4] : ia)
    {
        for (int & q : p)
        {
            std::cout << q << " ";
        }
        std::cout << std::endl;
    }

    // for loops using subscripts
    for (int p = 0; p != std::end(ia) - std::begin(ia); ++p)
    {
        for (int q = 0; q != std::end(ia[p]) - std::begin(ia[p]); ++q)
        {
            std::cout << ia[p][q] << " ";
        }
        std::cout << std::endl;
    }

    // for loops using pointers
    for (int (* p)[4] = std::begin(ia); p != std::end(ia); ++p)
    {
        for (int * q = std::begin(*p); q != std::end(*p); ++q)
        {
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
