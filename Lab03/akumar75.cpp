#include <iostream>

// Struct for result
struct SubArrResult {
    int low;
    int high;
    int sum;
};

//Max Subarray Problem with Divide-and-Conquer
SubArrResult findMaximumSubarray(int A[], int low, int high) {
    SubArrResult result;
    result.low = low;
    result.high = high;
    result.sum = A[low]; // Initialized with first element

    int currLow = low;
    int currSum = A[low];

    for (int i = low + 1; i <= high; i++) {
        // Compares current element with current subarray sum
        if (A[i] > (currSum + A[i])) {
            currLow = i;
            currSum = A[i];
        } else {
            currSum += A[i];
        }

        // Updates result if current sum is greater
        if (currSum > result.sum) {
            result.low = currLow;
            result.high = i;
            result.sum = currSum;
        }
    }

    return result;
}

// Finds maximum subarray with arrays
SubArrResult findMaximumSubarray(int A[], int low, int high);

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
    SubArrResult result = findMaximumSubarray(A, 0, n - 1);
    //Outputs Result
    std::cout << result.sum;
    // Deallocates dynamically allocated memory
    delete[] A;

    return 0;
}

