#include <iostream>
#include <vector>
#include <string>

std::vector<int> countFrogs(const std::string& s, const std::vector<int>& startIndex, const std::vector<int>& endIndex) {
    std::vector<int> result;
    for (int i = 0; i < startIndex.size(); i++) {
        int start = startIndex[i] - 1; // Convert to 0-indexed
        int end = endIndex[i] - 1; // Convert to 0-indexed
        int frogs = 0;
        bool foundFirstStone = false;
        for (int j = start; j <= end; j++) {
            if (s[j] == '|') {
                foundFirstStone = true;
            } else if (foundFirstStone && s[j] == '*') {
                frogs++;
            }
        }
        // If the last character is a stone, we need to count the frogs before it
        if (s[end] == '|') {
            int lastStoneIndex = end;
            while (lastStoneIndex > start && s[lastStoneIndex] != '|') {
                lastStoneIndex--;
            }
            for (int j = lastStoneIndex + 1; j < end; j++) {
                if (s[j] == '*') {
                    frogs++;
                }
            }
        }
        result.push_back(frogs);
    }
    return result;
}

int main() {
    std::string s;
    std::cout << "Enter the string: ";
    std::cin >> s;

    int n;
    std::cout << "Enter the number of start indices: ";
    std::cin >> n;

    std::vector<int> startIndex(n);
    std::cout << "Enter the start indices: ";
    for (int i = 0; i < n; i++) {
        std::cin >> startIndex[i];
    }

    std::cout << "Enter the number of end indices: ";
    std::cin >> n;

    std::vector<int> endIndex(n);
    std::cout << "Enter the end indices: ";
    for (int i = 0; i < n; i++) {
        std::cin >> endIndex[i];
    }

    std::vector<int> result = countFrogs(s, startIndex, endIndex);
    std::cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}