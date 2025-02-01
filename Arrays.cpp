#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int row, col;

    cout << "WELCOME!" << endl;

    // Take user input for the number of rows
    while (true) {
        cout << "\nEnter the row size of the array: ";
        cin >> row;
        if (cin.fail() || row <= 0) { // Validate if input is a number and not negative or 0
            cout << "Invalid input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    // Take user input for the number of columns
    while (true) {
        cout << "Enter the column size of the array: ";
        cin >> col;
        if (cin.fail() || col <= 0) { // Validate if input is a number and not negative or 0
            cout << "Invalid input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    // Take user input for each element of the array
    // Loop through each index and store the input in the array
    int arr[row][col], rowSums[row] = {0};
    for (int i = 0; i < row; i++) {
        cout << "\nData entry for row " << i + 1 << endl;
        for (int j = 0; j < col; j++) {
            while (true) {
                cout << "Enter a number for [" << i << "][" << j << "]: ";
                cin >> arr[i][j];
                if (cin.fail() || arr[i][j] < 0) { // Validate if input is a number and not negative or 0
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                break;
            }
            rowSums[i] += arr[i][j]; // Add element to rowSum[i]
        }
    }

    // Display contents of arr
    cout << "\nArray Content" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    int minIndex = 0, maxIndex = 0; // Assume first element in rowSums is lowest/highest

    // Loop through each element in rowSums to find index with lowest and highest value
    for (int i = 1; i < row; i++) {
        if (rowSums[i] < rowSums[minIndex]) 
            minIndex = i;   // Update index of lowest value
        if (rowSums[i] > rowSums[maxIndex]) 
            maxIndex = i;   // Update index of highest value 
    }

    int sumEven = 0, sumOdd = 0, countEven = 0, countOdd = 0;
    // Loop through each element in arr and add each even and odd number separately
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // Check if arr[i][j] is even or odd
            if (arr[i][j] % 2 == 0) { 
                sumEven += arr[i][j];   // Add all even numbers
                countEven++;            // Count all even numbers
            } else {
                sumOdd += arr[i][j];    // Add all odd numbers
                countOdd++;             // Count all odd numbers
            }
        }
    }
    
    // Display all results
    // Row with the lowest sum
    cout << "\nThe row with the lowest sum is in row: " << minIndex + 1 << " and the sum is: " << rowSums[minIndex]; 
    // Row with the highest sum 
    cout << "\nThe row with the highest sum is in row: " << maxIndex + 1 << " and the sum is: " << rowSums[maxIndex]; 
    // Sum of all even numbers
    cout << "\nThe total sum of all even numbers in Array is: " << sumEven;  
    // Sum of all odd numbers                                        
    cout << "\nThe total sum of all odd numbers in Array is: " << sumOdd;          
    // Average of all even numbers
    if (countEven > 0)
        cout << "\nThe average of all even numbers in Array is: " << fixed << setprecision(2) << double(sumEven) / countEven;                             
    else
        cout << "\nThere are no even numbers to find average of!";    
    // Average of all odd numbers                                                        
    if (countOdd > 0)
        cout << "\nThe average of all odd numbers in Array is: " << fixed << setprecision(2) << double(sumOdd) / countOdd;                                
    else
        cout << "\nThere are no odd numbers to find average of!";    

    return 0;
}
