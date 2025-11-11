#include <stdio.h>

void show(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5, i, pos, key, cap = 100;

    printf("Original array:\n");
    show(arr, n);

    // Search for key in the array
    key = 30;
    for(i = 0; i < n && arr[i] != key; i++);
    if(i < n) {
        printf("Found %d at index %d\n", key, i);
    } else {
        printf("%d not found in the array\n", key);
    }

    // Insert element 60 at position 2
    pos = 2;
    if(n < cap) {
        for(i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = 60;
        n++;
    }

    printf("After insertion:\n");
    show(arr, n);

    // Delete element at position 3
    pos = 3;
    if(pos >= 0 && pos < n) {
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    printf("After deletion:\n");
    show(arr, n);

    return 0;
}

