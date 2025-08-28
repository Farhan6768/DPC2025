#include <iostream>
#include <set>
#include <string>
using namespace std;

int countSubstrings(string s, int k) 
{
    int n = s.size();
    int result = 0;

    for (int i = 0; i < n; i++)
	 {
        set<char> st;
        for (int j = i; j < n; j++) 
		{
            st.insert(s[j]);
            if ((int)st.size() == k) result++;
            if ((int)st.size() > k) break;
        }
    }
    return result;
}

int main() 
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << countSubstrings(s, k) << endl;
    return 0;
}
/*
Enter string: pqpqs
Enter k: 2
7
  */
