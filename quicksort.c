#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

int main(){
    int n;
    printf("Enter the Number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int A[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    qs(A, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

