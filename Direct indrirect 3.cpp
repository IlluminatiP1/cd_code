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
void get_3_code(string expression)
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
}
void get_quad_code(string expression)
{
    int count = 0;
    stack<char> st;
    char x,y;
    char r='1';
    cout<<"\n";
    cout<<"res\targ1\top\targ2\n";
    for(char c : expression)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            count++;
            cout<<"t"<<count<<"\t";
            if(!isalpha(y))
            cout<<"t"<<y<<"\t"<<c<<"\t";
            else
            cout<<y<<"\t"<<c<<"\t";
            if(!isalpha(x))
            cout<<"t";
            cout<<x<<"\t"<<endl;
            st.push(r);
            r++;
        }
        else
        {
        st.push(c);
        }
    }
    r--;
}
void get_direct_code(string expression)
{
    int count = 0;
    stack<char> st;
    char x,y;
    char r='1';
    cout<<"\n";
    cout<<"   arg1\top\targ2\n";
    for(char c : expression)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            count++;
            cout<<count-1<<"   ";
            if(!isalpha(y))
            {
                y--;
            cout<<y<<"\t"<<c<<"\t";
            }
            else
            cout<<y<<"\t"<<c<<"\t";
            if(!isalpha(x))
            {
                x--;
            cout<<x<<endl;
            }
            else{
            cout<<x<<endl;
            }
            st.push(r);
            r++;
        }
        else
        {
        st.push(c);
        }
    }
    r--;
}
void get_indirect_code(string expression)
{
    int count = 0;
    stack<char> st;
    char x,y;
    char r='1';
    cout<<"\n";
    cout<<"arg1\top\targ2\n";
    for(char c : expression)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            count++;
            if(!isalpha(y))
            {
            cout<<y<<y<<"\t"<<c<<"\t";
            }
            else
            cout<<y<<"\t"<<c<<"\t";
            if(!isalpha(x))
            {
            cout<<x<<x<<endl;
            }
            else
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
}
int main() {
    string expr;
    cout<<"Enter the expression: ";
    cin>>expr;
    string infix = expr;
    string postfix = infixToPostfix(infix);
    cout<<"Quadraple Code is: \n";
    get_quad_code(postfix);
    cout<<"\n\nDirect Code is: \n";
    get_direct_code(postfix);
    cout<<"\n\nIndirect Code is: \n";
    get_indirect_code(postfix);
    cout<<"\n\nThree Address Code is: \n\n";
    get_3_code(postfix);
    return 0;
}