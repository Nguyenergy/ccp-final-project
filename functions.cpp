#include "functions.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Log a meal\n";
    cout << "2. View calorie log\n";
    cout << "3. Clear log\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void logMeal(const string& username) {
    string meal;
    int calories;
    ofstream file(username + "_log.txt", ios::app);

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    cout << "Enter meal description: ";
    getline(cin, meal);
    cout << "Enter calories: ";
    cin >> calories;

    while (cin.fail() || calories < 0) {
        cout << "Invalid input. Enter a valid calorie number: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> calories;
    }

    file << meal << " - " << calories << " calories" << endl;
    file.close();
    cout << "Meal logged!\n";
}

void viewLog(const string& username) {
    ifstream file(username + "_log.txt");
    string line;

    cout << "\n--- Calorie Log for " << username << " ---\n";
    if (!file) {
        cout << "No log found.\n";
        return;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void clearLog(const string& username) {
    ofstream file(username + "_log.txt", ios::trunc);
    file.close();
    cout << "Calorie log cleared.\n";
}
