#include <iostream>
using namespace std;

// arr is array heapified, n is size of heap, i is index of current node
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest element as current node
    int left = 2 * i + 1; // Index of left child of current node
    int right = 2 * i + 2; // Index of right child of current node

    // Checks of left child exists within heap boundaries
    // Checks if it is greater than current largest element
    // When true, index largest is updated to left
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than root
    //Works the same as left in above code
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, means current node is not largest 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapifies affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Builds max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //Extracts elements one-by-one from heap
    //Swaps root node with last element in heap
    for (int i = n - 1; i >= 0; i--) {
        //Moves current root to end
        swap(arr[0], arr[i]);

        //Calls max heapify on reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    //Inputs array size
    cin >> n;
    //Dynamically allocates memory for array
    int *A = new int[n];
    //Inputs elements of array
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    //Does Heapsort Function
    heapSort(A, n);
    //Outputs Result
    for (int i = 0; i < n; i++){
        cout << A[i] << ";";
    }
    return 0;
}
