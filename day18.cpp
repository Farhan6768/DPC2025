#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertSorted(stack<int>& st, int x)
 {
    if (st.empty() || st.top() <= x
	) 
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

void sortStack(stack<int>& st)
 {
    if (st.empty()) return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
}

int main() 
{
    stack<int> st;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> val;
        st.push(val);
    }

    sortStack(st);

    vector<int> result;
    while (!st.empty())
      {
        result.push_back(st.top());
        st.pop();
    }

    for (int i = 0; i < result.size(); i++)
	 {
        cout << result[i] << " ";
    }

    return 0;
}
/*
Enter number of elements: 4
Enter elements: 3 1 4 2
4 3 2 1
*/
