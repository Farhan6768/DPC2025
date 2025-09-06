#include <iostream>
#include <vector>
using namespace std;

int main()
 {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> result;

    for (int i = 0; i <= n - k; i++) 
	{
        int maxVal = arr[i];
        for (int j = i; j < i + k; j++) 
		{
            if (arr[j] > maxVal)
                maxVal = arr[j];
        }
        result.push_back(maxVal);
    }

    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
/*
Enter size of array: 8
Enter array elements: 1 3 -1 -3 5 3 6 7
Enter window size k: 3
Output: 3 3 5 5 6 7
  */
