#include <bits/stdc++.h>
using namespace std;
bool redundant_parenthesis(string s)
{
    stack<char> st;
    bool res=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='8' || s[i]=='/')
            st.push(s[i]);

        else if(s[i]=='(')
            st.push(s[i]);

        else if(s[i]==')'){
            if(s[i]=='('){
                return false;
            }
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    return true;
}
int main()
{
    string s="(((a+e)))";
    if(redundant_parenthesis(s))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    return 0;
}