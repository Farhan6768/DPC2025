#include <stdio.h>

int nextGap(int gap) 
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int i, j, gap = n + m;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    {
        for (i = 0; i + gap < n; i++) 
        {
            if (arr1[i] > arr1[i + gap])
            {
                int temp = arr1[i];
                arr1[i] = arr1[i + gap];
                arr1[i + gap] = temp;
            }
        }
        for (j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++)
          {
            if (arr1[i] > arr2[j]) 
            {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
              {
                if (arr2[j] > arr2[j + gap])
                {
                    int temp = arr2[j];
                    arr2[j] = arr2[j + gap];
                    arr2[j + gap] = temp;
                }
            }
        }
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int i;

    merge(arr1, arr2, n, m);

    printf("arr1: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    printf("\narr2: ");
    for (i = 0; i < m; i++)
        printf("%d ", arr2[i]);

    return 0;
}


