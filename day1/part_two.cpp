#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <regex>

int main(int argc, char **argv) {
    // Fields
    std::vector<int> leftList = {};
    std::vector<int> rightList = {};
    std::ifstream inputData("./input");
    std::regex const pattern(R"~(\d+)~");
    std::string buffer;
    int similarityScore = 0;
    
    // Make sure file was opened
    if (!inputData.is_open()) {
        std::cerr << "File failed to open" << std::endl;
        return 1;
    }

    while (std::getline(inputData, buffer)) {
        // Create regex iterators
        std::sregex_iterator begin(buffer.begin(), buffer.end(), pattern);
        std::sregex_iterator end;

        // Iterate over buffer
        std::vector<int> numbers;
        for (auto iter = begin; iter != end; iter++) {
            numbers.push_back(std::stoi(iter->str()));
        }

        // Enforce file structure
        if (numbers.size() == 2) {
            leftList.push_back(numbers[0]);
            rightList.push_back(numbers[1]);
        } else {
            std::cerr << "Bad file format" << std::endl;
            return 2;
        }
    }

    for (int lNumber : leftList) {
        int hitCount = 0;
        for (int rNumber : rightList) {
            if (lNumber == rNumber) {
                hitCount += 1;
            }
        }
        similarityScore += lNumber * hitCount;
    }

    std::cout << similarityScore << std::endl;

    return 0;
}