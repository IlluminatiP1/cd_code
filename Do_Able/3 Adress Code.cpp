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
void get_3_code(char start,string expression)
{
    int count = 0;
    stack<char> st;
    char x,y;
    char r='1';
    for(char c : expression)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            count++;
            cout<<"t"<<count<<"=";
            if(!isalpha(y))
            cout<<"t"<<y<<c;
            else
            cout<<y<<c;
            if(!isalpha(x))
            cout<<"t";
            cout<<x<<endl;
            st.push(r);
            r++;
        }
        else
        {
        st.push(c);
        }
    }
    r--;
    cout<<start<<"=t"<<r;
}
int main() {
    string expr;
    cout<<"Enter the expression: ";
    cin>>expr;
    cout<<"Three Address Code is: \n\n";
    string infix = expr.substr(2);
    string postfix = infixToPostfix(infix);
    get_3_code(expr[0],postfix);
    return 0;
}
