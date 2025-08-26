#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if(isValid(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*
Enter a string of brackets: [{()}]
true
  */
