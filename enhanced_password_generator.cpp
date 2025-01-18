#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeUppercase, bool includeNumbers, bool includeSpecialChars) {
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string specialChars = "!@#$%^&*()_+-=[]{}|;:',.<>?/";

    string characterSet = lowercase;
    if (includeUppercase) characterSet += uppercase;
    if (includeNumbers) characterSet += numbers;
    if (includeSpecialChars) characterSet += specialChars;

    // Ensure there is at least one character set
    if (characterSet.empty()) {
        throw invalid_argument("No character types selected. Cannot generate password.");
    }

    // Check if password length is valid
    int minRequired = (includeUppercase ? 1 : 0) + (includeNumbers ? 1 : 0) + (includeSpecialChars ? 1 : 0) + 1;
    if (length < minRequired) {
        throw invalid_argument("Password length is too short for the selected options.");
    }

    string password = "";
    unordered_set<int> usedIndices;

    // Guarantee at least one character from each selected type
    if (includeUppercase) {
        password += uppercase[rand() % uppercase.length()];
    }
    if (includeNumbers) {
        password += numbers[rand() % numbers.length()];
    }
    if (includeSpecialChars) {
        password += specialChars[rand() % specialChars.length()];
    }

    // Fill the rest of the password with random characters
    while (password.length() < length) {
        char randomChar = characterSet[rand() % characterSet.length()];
        if (usedIndices.find(randomChar) == usedIndices.end()) {
            password += randomChar;
            usedIndices.insert(randomChar);
        }
    }

    // Shuffle the password for randomness
    for (size_t i = 0; i < password.length(); i++) {
        swap(password[i], password[rand() % password.length()]);
    }

    return password;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generator

    int length;
    char includeUppercase, includeNumbers, includeSpecialChars;

    cout << "Welcome to the Enhanced Password Generator!\n";
    cout << "Enter the desired password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> includeUppercase;

    cout << "Include numbers? (y/n): ";
    cin >> includeNumbers;

    cout << "Include special characters? (y/n): ";
    cin >> includeSpecialChars;

    try {
        string password = generatePassword(
            length,
            (includeUppercase == 'y' || includeUppercase == 'Y'),
            (includeNumbers == 'y' || includeNumbers == 'Y'),
            (includeSpecialChars == 'y' || includeSpecialChars == 'Y')
        );

        cout << "\nYour generated password is: " << password << endl;
    } catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
