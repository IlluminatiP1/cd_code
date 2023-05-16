#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
using namespace std;

string arr[] = {"using", "namespace", "std", "int", "float", "double", "string ", " cin ", " cout ", " void ", " main ", " iostream ", " return ", " include "};

bool iskeyword(string a)
{
    for (int i = 0; i < 14; i++)
    {
        if (arr[i] == a)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    fstream file;
    string s, filename;
    filename = "./add.c";
    file.open(filename.c_str());

    while (file >> s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "=" || s == "==" || s == "&&" || s == "||" || s == "+=" || s == "-=" || s == "++" || s == "--")
        {
            cout << s << " is an operator";
            s = "";
        }
        else if (s == "(" || s == ")" || s == "{" || s == "}" || s == "[" || s == "]" || s == "<" || s == ">" || s == "<<" || s == ">>")
        {
            cout << s << " is a symbol";
            s = "";
        }
        else if (iskeyword(s))
        {
            cout << s << " is a keyword";
            s = "";
        }
        else if (isdigit(s[0]))
        {
            int x = 0;
            if (!isdigit(s[x++]))
                continue;
            else
            {
                cout << s << " is constant";
                s = "";
            }
        }
        else if (s == "\n" || s == " " || s == "")
        {
            s = "";
        }
        else
        {
            cout << s << " is an identifier";
        }
    }

    return 0;
}

//Create a file called add.c
//#include <stdio.h>
//void main(){
    //int x = 6;
    //int y = 4;
    //x = x + y;
    //printf("%d", x);}