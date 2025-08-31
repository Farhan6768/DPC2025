#include <iostream>
using namespace std;

int main()
 {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors: [";

    while (n % 2 == 0)
	 {
        cout << 2;
        n /= 2;
        if (n > 1) cout << ", ";
    }
    for (int i = 3; i * i <= n; i += 2)
	 {
        while (n % i == 0)
		 {
            cout << i;
            n /= i;
            if (n > 1) cout << ", ";
        }
    }

    if (n > 2) cout << n;

    cout << "]" << endl;

    return 0;
}
/*
Enter a number: 18
Prime factors: [2, 3, 3]
*/
