//Merge Sort Code with Vectors
#include <iostream>
#include <vector>

// Merge two sorted subarrays into a single sorted subarray
std::vector<int> merge(std::vector<int>& L, std::vector<int>& R) {
    int n1 = L.size();
    int n2 = R.size();
    int i = 0, j = 0;

    std::vector<int> S;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            S.push_back(L[i]);
            i++;
        } else {
            S.push_back(R[j]);
            j++;
        }
    }

    // Copies the remaining elements of L, if there are any
    while (i < n1) {
        S.push_back(L[i]);
        i++;
    }

    // Copies the remaining elements of R, if there are any
    while (j < n2) {
        S.push_back(R[j]);
        j++;
    }

    return S;
}

// Merge sort function
std::vector<int> mergeSort(std::vector<int>& A) {
    int n = A.size();

    //Array with 0 or 1 element is already sorted
    if (n <= 1) {
        return A;
    }

    int mid = n / 2;

    // Divides array into two halves
    std::vector<int> L(A.begin(), A.begin() + mid);
    std::vector<int> R(A.begin() + mid, A.end());

    // Recursively sorts left and right halves
    L = mergeSort(L);
    R = mergeSort(R);

    // Merges sorted halves
    return merge(L, R);
}

int main() {
    int value = 0;
    std::cin >> value;
    int temp;
    std::vector<int> nums;
    int num = 0;
    //continuous inputs
    for (int i = 0; i < value; i++){
      std::cin >> temp;
      nums.push_back(temp);
    }
    int arrSize = nums.size();
    std::vector<int> ans = mergeSort(nums);
    for (int i = 0; i < arrSize; i++){
      std::cout << ans[i] << ";";
    }
    return 0;
}
