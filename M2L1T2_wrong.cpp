#include <stdio.h>
#include <string.h>

void step(int* i, int* j, char* arr, char* arr_stack) {
    arr_stack[*j] = arr[*i];
    (*i)++;
    (*j)++;
}

int main(void) {
    char arr[1000];
    scanf("%s", arr);
    int arr_length = strlen(arr);
    char arr_stack[arr_length+1];

    int flag;
    do {
        flag = 0;
        int i = 0;
        int j = 0;
        while (i < arr_length) {
            if (arr[i] == arr[i+1]) {
                flag = 1;
                while (arr[i] == arr[i+1]) i++;
                if (flag) {
                    i++;
                    while(i < arr_length) step(&i, &j, arr, arr_stack);
                    break;
                }
            } else step(&i, &j, arr, arr_stack);
        }
        arr_stack[j] = '\0';
        arr_length = strlen(arr_stack);
        strncpy(arr, arr_stack, arr_length+1);
        //printf ("arr %s\n", arr);
    } while(flag);
    printf ("%s\n", arr_stack);
    return 0;
}
