#include <bits/stdc++.h>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    for (char c : infix) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
        else {
            postfix += c;
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+b*c-d";
    string postfix = infixToPostfix(infix);
    cout << "Infix notation: " << infix << endl;
    cout << "Postfix notation: " << postfix << endl;
    reverse(infix.begin(),infix.end());
    postfix = infixToPostfix(infix);
    reverse(postfix.begin(),postfix.end());
    cout << "Prefix notation: "<< postfix;
    return 0;
}
