#include <stdio.h>

int main(void) {
    int n;
    int element;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    scanf("%d", &element);
    int count = 0;
    for (int i = 0; i < n; ++i) if (arr[i] != element) count++;
    printf ("%d\n", count);
    return 0;
}
