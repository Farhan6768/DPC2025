#include <stdio.h>

void findLeaders(int arr[], int n) {
    int leaders[n];  
    int count = 0;

    int max_from_right = arr[n - 1]; 
    leaders[count++] = max_from_right; 

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            leaders[count++] = arr[i];
        }
    }
    printf("Leaders: [");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", leaders[i]);
        if (i > 0) printf(", ");
    }
    printf("]\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);

    return 0;
}
