#include <iostream>

int main()
{
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;

    while(std::cin >> ch)
    {
        if (ch == 'a')
            ++a_cnt;
        else if (ch == 'e')
            ++e_cnt;
        else if (ch == 'i')
            ++i_cnt;
        else if (ch == 'o')
            ++o_cnt;
        else if (ch == 'u')
            ++u_cnt;
    }

    std::cout << "Number of vowel a: " << a_cnt << std::endl;
    std::cout << "Number of vowel e: " << e_cnt << std::endl;
    std::cout << "Number of vowel i: " << i_cnt << std::endl;
    std::cout << "Number of vowel o: " << o_cnt << std::endl;
    std::cout << "Number of vowel u: " << u_cnt << std::endl;
}
