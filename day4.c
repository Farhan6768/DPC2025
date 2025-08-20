#include <stdio.h>

void findZeroSumSubarrays(int arr[], int n) 
{
    int found = 0;
    printf("Output: [");

    for (int i = 0; i < n; i++)
      {
        int sum = 0;
        for (int j = i; j < n; j++)
          {
            sum += arr[j];
            if (sum == 0) {
                if (found) printf(", ");
                printf("(%d, %d)", i, j);
                found = 1;
            }
        }
    }

    printf("]\n");

    if (!found) {
        printf("No subarray with zero sum found.\n");
    }
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findZeroSumSubarrays(arr, n);

    return 0;
}
#Output: [(0, 2), (2, 3)]
