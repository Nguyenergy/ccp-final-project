#include <iostream>
#include "functions.h"
#include <limits>


using namespace std;

int main() {
    int choice;
    string username;

    cout << "Welcome to the Calorie Tracker!\n";
    cout << "Enter your name: ";
    getline(cin, username);

    do {
        showMenu();
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> choice;
        }

        switch (choice) {
            case 1:
                logMeal(username);
                break;
            case 2:
                viewLog(username);
                break;
            case 3:
                clearLog(username);
                break;
            case 4:
                cout << "Goodbye, " << username << "!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
