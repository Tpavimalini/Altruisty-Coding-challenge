#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int k;
    std::cout << "Enter the length of the segment: ";
    std::cin >> k;

    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = *std::max_element(arr.begin(), arr.end());
    std::cout << "Maximum of minimums: " << result << std::endl;

    return 0;
}