#include <iostream>
#include <vector>
#include <limits> // For numeric limits

using namespace std;

void logTemperature(vector<int>& temperatures) {
    int temp;
    cout << "Enter the temperature for the day (-100 to stop): ";
    while (cin >> temp && temp != -100) {
        temperatures.push_back(temp);
        cout << "Temperature logged. Enter another temperature (-100 to stop): ";
    }
}

void displayStatistics(const vector<int>& temperatures) {
    if (temperatures.empty()) {
        cout << "No temperatures logged yet.\n";
        return;
    }

    int sum = 0, highest = INT_MIN, lowest = INT_MAX;

    for (int temp : temperatures) {
        sum += temp;
        if (temp > highest) highest = temp;
        if (temp < lowest) lowest = temp;
    }

    double average = static_cast<double>(sum) / temperatures.size();

    cout << "\n--- Temperature Statistics ---\n";
    cout << "Average Temperature: " << average << "°\n";
    cout << "Highest Temperature: " << highest << "°\n";
    cout << "Lowest Temperature: " << lowest << "°\n";
}

int main() {
    vector<int> temperatures;
    int choice;

    do {
        cout << "\n--- Weather Logger Menu ---\n";
        cout << "1. Log Temperature\n";
        cout << "2. Display Statistics\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                logTemperature(temperatures);
                break;
            case 2:
                displayStatistics(temperatures);
                break;
            case 3:
                cout << "Exiting Weather Logger. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
