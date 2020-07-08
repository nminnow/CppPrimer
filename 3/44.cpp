#include <iostream>
#include <iterator>

int main()
{
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // range-based for loops
    using ref_int4 = int (&)[4];
    using ref_int = int &;
    for (ref_int4 p : ia)
    {
        for (ref_int q : p)
        {
            std::cout << q << " ";
        }
        std::cout << std::endl;
    }

    // for loops using pointers
    using ptr_int4 = int (*)[4];
    using ptr_int = int *;
    for (ptr_int4 p = std::begin(ia); p != std::end(ia); ++p)
    {
        for (ptr_int q = std::begin(*p); q != std::end(*p); ++q)
        {
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
