#include <iostream>

int main()
{
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    int space_cnt = 0, tab_cnt = 0, newline_cnt = 0;
    int ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    char ch;
    bool seq = false;

    while (std::cin >> ch)
    {
        if (ch == 'f')
        {
            seq = true;
        }
        else
        {
            switch (ch)
            {
                case 'a': case 'A':
                    ++a_cnt;
                    break;
                case 'e': case 'E':
                    ++e_cnt;
                    break;
                case 'i': case 'I':
                    ++i_cnt;
                    if (seq)
                    {
                        ++fi_cnt;
                    }
                    break;
                case 'o': case 'O':
                    ++o_cnt;
                    break;
                case 'u': case 'U':
                    ++u_cnt;
                    break;
                case ' ':
                    ++space_cnt;
                    break;
                case '\t':
                    ++tab_cnt;
                    break;
                case '\n':
                    ++newline_cnt;
                    break;
                case 'l':
                    if (seq)
                    {
                        ++fl_cnt;
                    }
                    break;
                case 'f':
                    if (seq)
                    {
                        ++ff_cnt;
                    }
                    break;
                default:
                    break;
            }
            seq = false;
        }
    }

    std::cout << "Number of vowel a: " << a_cnt << std::endl;
    std::cout << "Number of vowel e: " << e_cnt << std::endl;
    std::cout << "Number of vowel i: " << i_cnt << std::endl;
    std::cout << "Number of vowel o: " << o_cnt << std::endl;
    std::cout << "Number of vowel u: " << u_cnt << std::endl;
    std::cout << "Number of blank spaces: " << space_cnt << std::endl;
    std::cout << "Number of tabs: " << tab_cnt << std::endl;
    std::cout << "Number of 2-character sequence ff: " << ff_cnt << std::endl;
    std::cout << "Number of 2-character sequence fl: " << fl_cnt << std::endl;
    std::cout << "Number of 2-character sequence fi: " << fi_cnt << std::endl;
}
