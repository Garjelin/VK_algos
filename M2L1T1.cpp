#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int res = -1;
    for (int i = n-1; i >= 0; --i) {
        if (arr[i]%2 == 0) {
            res = arr[i];
            break;
        }
    }
    printf ("%d\n", res);
    return 0;
}
