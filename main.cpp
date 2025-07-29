#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>

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
    std::ifstream inputfile("doc1.txt");
    if (!inputfile.is_open())
    {
        std::cerr << "error opening the file" << std::endl;
        return 1;
    }
    std::cout << "Reading words from file..." << std::endl;
    std::vector<std::string> docwords;
    std::string docword;
    std::cout << "Cleaning and normalizing words..." << std::endl;
    while (inputfile >> docword)
    {
        remove_punctuation(docword);
        to_lowercase(docword);
        docwords.push_back(docword);
    }
    std::cout << "Cleaning complete." << std::endl;

    return 0;
}