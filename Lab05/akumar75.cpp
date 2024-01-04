#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform counting sort on a specific digit place (digit)
// Takes in 2D Vector which is array and exp parameter is the placement
// of the current place of the digit
void countingSort(vector<vector<int>>& array, int digit) {
    //number of vectors in input
    int n = array.size();
    //creates result of same size as input with zeros in it
    vector<vector<int>> result(n, vector<int>(10, 0));
    //Stores count of occurrences of each digit
    vector<int> count(10, 0);

    // Counts occurrences of digits at current place value
    for (int i = 0; i < n; ++i) {
        int index = (array[i][digit] % 10);
        count[index]++;
    }
    // Calculates cumulative count
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    // Places elements in output array
    for (int i = n - 1; i >= 0; --i) {
        int index = (array[i][digit] % 10);
        result[count[index] - 1] = array[i];
        count[index]--;
    }
    // Copies output array back to original array
    for (int i = 0; i < n; ++i) {
        array[i] = result[i];
    }
}

// Function performs radixSort on vectors
void radixSort(vector<vector<int>>& array) {
    // Performs counting sort for digit places from rightmost to leftmost
    for (int digit = 9; digit >= 0; --digit) {
        countingSort(array, digit);
    }
}

int main() {
    int n;
    //input for size of rows
    cin >> n;
    vector<vector<int>> array(n, vector<int>(10, 0));
    // Inputs vectors
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> array[i][j];
        }
    }
    // Performs radix sort
    radixSort(array);
    // Outputs sorted vectors in specified format
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << array[i][j];
            if (j < 10) {
                cout << ";";
            }
        }
        cout << endl;
    }
    return 0;
}