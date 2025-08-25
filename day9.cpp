#include <bits/stdc++.h>
using namespace std;

vector<string> getPermutations(string s)
 {
    vector<string> result;
    sort(s.begin(), s.end());
    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return result;
}

int main()
 {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> perms = getPermutations(s);

    cout << "All unique permutations:\n";
    for (int i = 0; i < perms.size(); i++) 
	{
        cout << perms[i] << "\n";
    }
    return 0;
}
/*Output:
Enter a string: abc
All unique permutations:
abc
acb
bac
bca
cab
cba
*/
