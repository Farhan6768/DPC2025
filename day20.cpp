#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
{
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    for (int i = 0; i < n; i++)
{
        int count = 0;
        for (int j = 0; j < n; j++) 
{
            if (arr[i] == arr[j])
                count++;
        }
        if (count == k) 
{
            cout << arr[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
/*
Enter size of array: 9
Enter elements: 3 1 4 4 5 2 6 1 4
Enter k: 2
1*/
