#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Utility Functions ---------- */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int src[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

/* ---------- MERGE SORT ---------- */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* ---------- HEAP SORT ---------- */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

/* ---------- QUICK SORT ---------- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------- RANDOMIZED QUICK SORT ---------- */
int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;

    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

/* ---------- MAIN FUNCTION ---------- */
int main() {
    printf("------Sandeep Mainali------\n");
    int original[] = {64, 25, 12, 22, 11};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[n];
    int choice = 1;

    srand(time(NULL));

    while (choice != 0) {
        printf("\n------ SORTING MENU ------\n");
        printf("1. Merge Sort\n");
        printf("2. Heap Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Randomized Quick Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        copyArray(original, arr, n);

        printf("Original Array: ");
        printArray(arr, n);

        switch (choice) {
            case 1:
                mergeSort(arr, 0, n - 1);
                printf("After Merge Sort: ");
                break;
            case 2:
                heapSort(arr, n);
                printf("After Heap Sort: ");
                break;
            case 3:
                quickSort(arr, 0, n - 1);
                printf("After Quick Sort: ");
                break;
            case 4:
                randomizedQuickSort(arr, 0, n - 1);
                printf("After Randomized Quick Sort: ");
                break;
            default:
                printf("Invalid Choice!\n");
                continue;
        }

        printArray(arr, n);
    }

    printf("\nProgram Terminated.\n");
    return 0;
}
