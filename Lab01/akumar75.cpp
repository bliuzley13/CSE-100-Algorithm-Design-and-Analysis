//Insertion Sort Code
#include <iostream>

void insertionSort(int arr[], int num){
  for (int i = 1; i < num; i++){
    int tik = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > tik){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=tik;

  }
}
  

int main() {
  //first int being the size of the array
  int value = 0;
  std::cin >> value;
  int arr[value];
  int num = 0;
  //continuous inputs
  for (int i = 0; i < value; i++){
    std::cin >> arr[i];
  }

  //Does work with the code snapshots to print out insertion sort
  for (int i = 1; i <= value; i++){
    insertionSort(arr, i);
    for (int j = 0; j < i; j++){
      //skips the 1st digit input
      if (i > 1)
        std::cout << arr[j];
      //adds the semicolons
      if (j < i-1){
        std::cout << ";";
      }
    }
    //adds the semicolon at the end
    if (i > 1){
      std::cout << ";";
      std::cout << std::endl;
    }
  }
  return 0;
}
