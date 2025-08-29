#include <iostream>
#include <string>
using namespace std;

int main()
 {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();
    int maxLen = 0, start = 0;
    int lastIndex[256];  
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    for (int i = 0; i < n; i++)
	 {
        if (lastIndex[s[i]] >= start)
		 {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }

    cout << maxLen << endl;
    return 0;
}
/*
Enter a string: abcabcbb
3
*/
