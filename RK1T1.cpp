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
    int n, even = 0, not_even = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i]%2 == 0) even++;
        else not_even++;
    }
    int arr_even[even], arr_not_even[not_even];
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
        if (arr[i]%2 == 0) {
            arr_even[j] = arr[i];
            j++;
        }
        else {
            arr_not_even[k] = arr[i];
            k++;
        }
    }
    
    int i = 0;
    for (int j = 0; j < even; ++j) {
        arr[i] = arr_even[j];
        i++;
    }
    for (int k = 0; k < not_even; ++k) {
        arr[i] = arr_not_even[k];
        i++;
    }
    for (int i = 0; i < n-1; ++i) printf("%d ", arr[i]);
    printf("%d\n", arr[n-1]);
    return 0;
}
