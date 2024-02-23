#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != 0) {
            arr2[j] = arr1[i];
            j++;
        }
    }
    for (; j<n; ++j) {
        arr2[j] = 0;
    }
    for (int i = 0; i < n-1; ++i) printf("%d ", arr2[i]);
    printf("%d", arr2[n-1]);
    return 0;
}
