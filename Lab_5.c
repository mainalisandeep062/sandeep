#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;

    return partition(arr, low, high);
}




int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = randomPartition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, low, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;  
}

int main() {
    int arr[] = {11, 9, 5, 18, 6 , 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;  

    int result = quickSelect(arr, 0, n - 1, k - 1); 

    if (result != -1)
        printf("%d-th smallest element is: %d\n", k, result);
    else
        printf("Invalid input!\n");

    return 0;
}