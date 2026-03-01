//5. Write a program in C to find the second largest element in an array.
#include <stdio.h>

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5, i;
    int f = arr[0], s = arr[0], found = 0;
    for (i = 1; i < n; i++)
        if (arr[i] > f)
            f = arr[i];
    for (i = 0; i < n; i++) {
        if (arr[i] != f) {
            s = arr[i];
            found = 1;
            break;
        }
    }
    if (!found)
        return 0;
    for (i = 0; i < n; i++)
        if (arr[i] > s && arr[i] != f)
            s = arr[i];
    printf("Second largest: %d\n", s);
    return 0;
}
