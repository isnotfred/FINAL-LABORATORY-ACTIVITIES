#include <iostream>
#include <iomanip>
using namespace std;

void ODD_NUMBER() {
    int endNum, startNum;

    // Get starting number
    while (true) {
        cout << "Enter starting number: ";
        cin >> startNum;
        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(startNum <= 0) { // Validate if input is non-negative or not zero
            cout << "Invalid input!";
            cout << "\nNumber must not be negative or zero!" << endl;
            continue;
        }
        break;
    }
    // Get end number
    while (true) {
        cout << "Enter end number: ";
        cin >> endNum;
        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;;
        }
        if (endNum <= 0) { // Validate if input is non-negative or not zero
            cout << "Invalid Input!";
            cout << "\nNumber must not be negative or zero!" << endl;
            continue;
        }
        if (endNum < startNum) { // Validate if end number is greater than starting number
            cout << "Invalid Input!";
            cout << "\nEnd number must be greater than the starting number!" << endl;
            continue;
        }
        break;
    }
    // Display all odd numbers between starting number and end number
    cout << "The odd numbers between " << startNum << " and " << endNum << " are: " << endl;
    for (int i = startNum; i <= endNum; i++) {
        if (i % 2 == 1)
            cout << i << endl;
    }
}

void SUM_AVERAGE() {
    double startNum, endNum, count = 0, sum = 0;

    // Get starting number
    while (true) {
        cout << "Enter starting number: ";
        cin >> startNum;
        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (startNum <= 0) { // Validate if input is non-negative or not zero
            cout << "Invalid Input!";
            cout << "\nNumber must not be negative or zero!" << endl;
            continue;
        }
        break;
    }
    // Get end number
    while (true) {
        cout << "Enter end number: ";
        cin >> endNum;
        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;;
        }
        if (endNum <= 0) { // Validate if input is non-negative or not zero
            cout << "Invalid Input!";
            cout << "\nNumber must not be negative or zero!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (endNum <= startNum) { // Validate if end number is greater than starting number
            cout << "Invalid Input!";
            cout << "\nEnd number must be greater than the starting number!" << endl;
            continue;
        }
        break;
    }
    // Calculate and display sum and average of numbers between starting and end number
    for (int i = startNum; i <= endNum; sum += i++, count++);
    cout << "The sum is: " << sum;
    cout << "\nThe Average is: " << fixed << setprecision(2) << sum / count << endl;
}

void FACTORIAL() {
    int number;

    // Get number
    while (true) {
        cout << "Enter a positive number: ";
        cin >> number;
        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(number <= 0){ // Validate if input is non-negative or not zero
            cout << "Invalid input!";
            cout << "\nNumber must not be negative or zero!" << endl;
            continue;
        }
        break;
    }
    // Calculate for the factorial of number
    long long factorial = 1;
    for (int i = 1; i <= number; ++i){
        factorial *= i;
    }
    cout << "The factorial of " << number << " is " << factorial << endl;
} 

int main() {
    int choice;

    // Prompt user to pick from 4 choices
    do {
        cout << "OPTIONS:";
        cout << "\n1 - Display ODD numbers";
        cout << "\n2 - SUM and AVERAGE";
        cout << "\n3 - Get FACTORIAL";
        cout << "\n4 - Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (cin.fail()) { // Validate if input is an integer
            cout << "Invalid input!";
            cout << "\nYou entered a non-integer value for a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            ODD_NUMBER();
            break;
        case 2:
            SUM_AVERAGE();
            break;
        case 3:
            FACTORIAL();
            break;
        case 4:
            cout << "Thank you!";
            break;
        default:
            cout << "Invalid option! Please choose from 1-4" << endl; 
        }
    } while (cin.fail() || choice != 4); // Loop until "4 - Exit" is chosen 
    return 0;
}