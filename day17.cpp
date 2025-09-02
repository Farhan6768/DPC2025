#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() 
{
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);

    stack<int> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            int num;
            stringstream convert(token);
            convert >> num;   // convert string to int
            st.push(num);
        }
    }

    cout << "Result: " << st.top() << endl;
    return 0;
}
/*
Enter postfix expression: 2 1 + 3 *
Result: 9
*/
