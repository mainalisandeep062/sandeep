#include <stdio.h>
#define SIZE 20

void insertElement(int arr[],int *n){
    int i;
    printf("Enter number of elements: ");
    scanf("%d",n);
    printf("Enter %d elements:\t",*n);
    for(i=0;i<*n;i++) scanf("%d",&arr[i]);
}

void displayElement(int arr[],int n){
    int i;
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void bubbleSort(int arr[],int n){
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(arr[j]>arr[j+1]){
                t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
    printf("Sorted Array:\t");
    displayElement(arr,n);
}

void selectionSort(int arr[],int n){
    int i,j,min,t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min]) min=j;
        t=arr[i]; arr[i]=arr[min]; arr[min]=t;
    }
    printf("Sorted Array:\t");
    displayElement(arr,n);
}

void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i]; j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j]; j--;
        }
        arr[j+1]=key;
    }
    printf("Sorted Array:\t");
    displayElement(arr,n);
}

int main(){
    int arr[SIZE],n=0,choice;
    char ch='y';

    while(ch=='y' || ch=='Y'){
        printf("1. Insert Element\n"
               "2. Display Element\n"
               "3. Bubble Sort\n"
               "4. Selection Sort\n"
               "5. Insertion Sort\n"
               "Enter choice (1-5): ");
        scanf("%d",&choice);

        switch(choice){
            case 1: insertElement(arr,&n); break;
            case 2: displayElement(arr,n); break;
            case 3: bubbleSort(arr,n); break;
            case 4: selectionSort(arr,n); break;
            case 5: insertionSort(arr,n); break;
            default:printf("Invalid Choice!! "); return 0;
        }

        printf("\nWant to Continue? (y/n): ");
        scanf(" %c",&ch);
    }
    return 0;
}
