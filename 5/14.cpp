#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> words;
    std::vector<int> counts;
    std::string word;
    int max[2] = {0, 0};

    while (std::cin >> word)
    {
        bool dup = false;
        for (decltype(words.size()) w = 0; w != words.size(); ++w)
        {
            if (words[w] == word)
            {
                dup = true;
                ++counts[w];
                if (counts[w] > max[1])
                {
                    max[0] = w;
                    max[1] = counts[w];
                }
            }
        }
        if (!dup)
        {
            words.push_back(word);
            counts.push_back(1);
        }
    }

    if (max[1] == 1 || max[1] == 0)
    {
        std::cout << "No word was repeated." << std::endl;
    }
    else
    {
        std::cout << "The word “" << words[max[0]] << "” occured " << max[1]
                  << " times." << std::endl;
    }
}
