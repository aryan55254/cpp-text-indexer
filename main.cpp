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
    return 0;
}