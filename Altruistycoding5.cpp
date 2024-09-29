#include <iostream>
#include <vector>
#include <algorithm>

// Function to validate the input value
bool isValidOxygenValue(int value) {
    return 1 <= value && value <= 100;
}

// Function to calculate the average oxygen levels for each trainee
// and determine the highest average oxygen level.
void calculateAverages(const std::vector<int>& oxygenValues) {
    std::vector<int> trainees[3];  // Create a vector for each trainee

    // Fill the trainees' oxygen level data considering valid input
    for (int i = 0; i < oxygenValues.size(); i++) {
        if (isValidOxygenValue(oxygenValues[i])) {
            trainees[i % 3].push_back(oxygenValues[i]);
        } else {
            std::cout << "INVALID INPUT" << std::endl;
            return;  // Invalidate the entire dataset since there's an invalid input
        }
    }

    // Calculate averages
    double averages[3];
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int value : trainees[i]) {
            sum += value;
        }
        averages[i] = sum / trainees[i].size();
    }

    double maxAverage = *std::max_element(averages, averages + 3);
    if (maxAverage < 70) {
        std::cout << "All trainees are unfit." << std::endl;
        return;
    }

    // Find the trainees with the highest average oxygen level
    for (int i = 0; i < 3; i++) {
        if (averages[i] == maxAverage) {
            std::cout << "Trainee Number : " << i + 1 << std::endl;
        }
    }
}

int main() {
    std::vector<int> oxygenValues(9);
    std::cout << "Enter the oxygen values for each trainee in each round: " << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cin >> oxygenValues[i];
    }

    calculateAverages(oxygenValues);

    return 0;
}