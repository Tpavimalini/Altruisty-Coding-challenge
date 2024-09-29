#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

int maxProfit(std::vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = std::min(minPrice, price);
        maxProfit = std::max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main() {
    int n;
    std::cout << "Enter the number of days: ";
    std::cin >> n;

    std::vector<int> prices(n);
    std::cout << "Enter the prices for each day: ";
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    int profit = maxProfit(prices);
    std::cout << "Maximum profit: " << profit << std::endl;

    return 0;
}