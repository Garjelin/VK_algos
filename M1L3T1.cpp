#include <stdio.h>

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
    
    insertionSort(arr1, n);

    for (int i = 0; i < n-1; ++i) printf("%d ", arr1[i]);
    printf("%d\n", arr1[n-1]);
    return 0;
}
