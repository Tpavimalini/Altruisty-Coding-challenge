#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cout << "Enter the number of balloons: ";
    std::cin >> n;

    std::vector<char> balloons(n);
    std::cout << "Enter the colors of the balloons: ";
    for (int i = 0; i < n; i++) {
        std::cin >> balloons[i];
    }

    std::unordered_map<char, int> count;
    for (char balloon : balloons) {
        count[balloon]++;
    }

    for (char balloon : balloons) {
        if (count[balloon] % 2 != 0) {
            std::cout << "The color of the balloon which is present odd number of times is: " << balloon << std::endl;
            return 0;
        }
    }

    std::cout << "All are even" << std::endl;

    return 0;
}