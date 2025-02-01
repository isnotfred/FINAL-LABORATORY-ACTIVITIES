#include <iostream>
using namespace std;

// Declare function prototypes
int getUserInput(string order);                     // Function to get user's input and validate it
int getGreatestCommonFactor(int x, int y);          // Function to calculate the Greatest Common Factor (GCF) using the Euclidean algorithm
int getLeastCommonMultiple(int x, int y, int GCF);  // Function to get the Least Common Multiple (LCM) using the formula (x * y) / GCF
void listCommonDivisors(int x, int y);              // Function to list all common divisors of two numbers

int main() {
    int num1, num2, GCF;

    cout << "WELCOME!" << endl;
    // Get user input for 2 numbers
    num1 = getUserInput("first");
    num2 = getUserInput("second");
    GCF = getGreatestCommonFactor(num1, num2);

    // Display results
    cout << "\nThe Greatest Common Factor (GCF) of " << num1 << " and " << num2 << " is: " << GCF;
    cout << "\nThe Least Common Multiple of " << num1 << " and " << num2 << " is: " << getLeastCommonMultiple(num1, num2, GCF);
    listCommonDivisors(num1, num2);

    return 0;
}

// Function to get user's input and validate it
int getUserInput(string order) {
    int x;
    while (true) {
        cout << "Enter the " << order << " number: ";
        cin >> x;
        if (cin.fail() || x <= 0) { // Validate if input is a number and not negative or 0
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    return x;
}

// Function to calculate the Greatest Common Factor (GCF) using the Euclidean algorithm
int getGreatestCommonFactor(int x, int y) {
    int temp;
    if (y > x) { // Ensure 'x' is the larger number
        temp = x;
        x = y;
        y = temp;
    }
    while (y != 0) { // Apply Euclidean algorithm until remainder is 0
        temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to get the Least Common Multiple (LCM) using the formula (x * y) / GCF
int getLeastCommonMultiple(int x, int y, int GCF) {
    int LCM;
    LCM = (x * y) / GCF; 
    return LCM;
}

// Function to list all common divisors of two numbers
void listCommonDivisors(int x, int y) {
    int min;
    x < y ? min = x : min = y;  // Determine the smaller number
    
    // Loop through numbers from 1 to the smaller number
    cout << "\nThe Common Divisors of " << x << " and " << y << " are: ";
    bool first = true;
    for (int i = 1; i <= min; i++) {
        if (x % i == 0 && y % i == 0) { // Check if 'i' is a divisor of both numbers
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }   
}