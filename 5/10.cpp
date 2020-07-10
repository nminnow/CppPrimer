#include <iostream>

int main()
{
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;

    while (std::cin >> ch)
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                ++a_cnt;
                break;
            case 'e':
            case 'E':
                ++e_cnt;
                break;
            case 'i':
            case 'I':
                ++i_cnt;
                break;
            case 'o':
            case 'O':
                ++o_cnt;
                break;
            case 'u':
            case 'U':
                ++u_cnt;
                break;
            default:
                break;
        }
    }

    std::cout << "Number of vowel a: " << a_cnt << std::endl;
    std::cout << "Number of vowel e: " << e_cnt << std::endl;
    std::cout << "Number of vowel i: " << i_cnt << std::endl;
    std::cout << "Number of vowel o: " << o_cnt << std::endl;
    std::cout << "Number of vowel u: " << u_cnt << std::endl;
}
