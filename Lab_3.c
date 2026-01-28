#include <stdio.h>
int n, arr[100], min, max, min1, max1, min2, max2, mid;

void MinMax(int arr[], int l, int r)
{

    /* Case 1: Only one element */
    if (l == r)
    {
        min = max = arr[l];
        return;
    }

    /* Case 2: Two elements */
    if (l == r - 1)
    {
        if (arr[l] < arr[r])
        {
            min = arr[l];
            max = arr[r];
        }
        else
        {
            min = arr[r];
            max = arr[l];
        }
        return;
    }

    /* Case 3: More than two elements */
    mid = (l + r) / 2;

    /* Left half */
    MinMax(arr, l, mid);
    min1 = min;
    max1 = max;

    /* Right half */
    MinMax(arr, mid + 1, r);
    min2 = min;
    max2 = max;

    /* Combine results */
    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
}
void insertElement()
{
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int BinarySearch(int arr[], int l, int r, int key)
{
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] > key)
        {
            return BinarySearch(arr, l, m - 1, key);
        }
        else
        {
            return BinarySearch(arr, m + 1, r, key);
        }
    }
    return -1;
}

int main()
{
    int opr, key;
    do
    {
        printf("\nEnter 1 for Minimax finding algorithm");
        printf("\nEnter 2 for Binary search");
        printf("\nEnter 3 for exit");
        printf("\nEnter the operation(1-3): ");
        scanf("%d", &opr);
        switch (opr)
        {
        case 1:
            insertElement();
            MinMax(arr, 0, n - 1);
            printf("Minimum element = %d\n", min);
            printf("Maximum element = %d\n", max);
            break;
        case 2:
            printf("\nEnter Elements in ascending order\n");
            insertElement();
            printf("Enter key to search: ");
            scanf("%d", &key);
            printf("Key is found at index: %d\n", BinarySearch(arr, 0, n - 1, key));
            break;
        case 3:
            printf("Exit successfully");
            break;
        default:
            printf("Please Enter a valid operation\n");
            break;
        }
    } while (opr != 3);
    return 0;
}