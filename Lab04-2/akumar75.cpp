#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

using namespace std;

// Function partitions array and returns index at pivot start
int randomized_partition(int arr[], int low, int high) {
    // Chooses random pivot index
    int pivotIndex = low + rand() % (high - low + 1);
    
    // Swaps pivot element with last element in subarray
    swap(arr[pivotIndex], arr[high]);
    
    // Standard partition process
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Places pivot element in correct position
    swap(arr[i + 1], arr[high]);
    
    // Returns index where pivot element is placed
    return i + 1;
}

// Function performs randomized quicksort
void randomized_quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partitions array and gets pivot index
        int pivotIndex = randomized_partition(arr, low, high);
        
        // Recur subarrays
        randomized_quicksort(arr, low, pivotIndex - 1);
        randomized_quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    // Inputs array size
    std::cin >> n;
    // Dynamically allocates memory for array
    int *A = new int[n];
    // Inputs elements of array
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    //Does Randomized Quicksort
    randomized_quicksort(A, 0, n-1);
    //Outputs Result
    for (int i = 0; i < n; i++){
        cout << A[i] << ";";
    }
    return 0;
}

