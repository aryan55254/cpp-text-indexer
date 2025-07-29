#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <limits>

void to_lowercase(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
};

void remove_punctuation(std::string &str)
{
    str.erase(
        std::remove_if(str.begin(), str.end(),
                       [](unsigned char c)
                       { return std::ispunct(c); }),
        str.end());
}

int main()
{
    std::vector<std::string> filenames = {"doc1.txt", "doc2.txt", "doc3.txt"};
    std::map<std::string, std::set<std::string>> word_index;
    for (std::string filename : filenames)
    {
        std::ifstream inputfile(filename);
        if (!inputfile.is_open())
        {
            std::cerr << "error opening the file" << std::endl;
            return 1;
        };
        std::vector<std::string> docwords;
        std::string docword;
        while (inputfile >> docword)
        {
            remove_punctuation(docword);
            to_lowercase(docword);
            docwords.push_back(docword);
        }

        for (std::string word : docwords)
        {
            word_index[word].insert(filename);
        };
    }
    std::cout << "\n--- Index built. Type 'y' to start search  ---\n";
    char keepgoing;
    std::cin >> keepgoing;
    while (keepgoing == 'y')
    {
        std::string userinput;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "enter a word to search (or press ctrl + c to quit): " << std::endl;
        while (!std::getline(std::cin, userinput))
        {
            std::cout << "invalid input , enter a string : " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        };
        remove_punctuation(userinput);
        to_lowercase(userinput);
        auto it = word_index.find(userinput);

        if (it != word_index.end())
        {
            std::cout << userinput << " = [ ";

            for (const std::string &filename : it->second)
            {
                std::cout << filename << " ";
            }

            std::cout << "]" << std::endl;
        }
        else
        {

            std::cout << "Sorry, the word '" << userinput << "' was not found in any file." << std::endl;
        }
        std::cout << "continue searrching (y/n) : " << std::endl;
        std::cin >> keepgoing;
    }

    return 0;
}