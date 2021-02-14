/*

link :https://leetcode.com/problems/valid-parentheses/


Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char&c:s){
            switch(c){
                case '(':st.push(c);break;
                case '{':st.push(c);break;
                case '[':st.push(c);break;
                case ']':if(st.empty() || st.top()!='[')return false;
                    else{
                        st.pop();
                        break;
                    }
                case '}':if(st.empty() || st.top()!='{')return false;
                    else{
                        st.pop();
                        break;
                    }
                case ')':if(st.empty() || st.top()!='(')return false;
                    else{
                        st.pop();
                        break;
                    }
                default:;
            }
        }
        return st.empty();
    }
};

int main(){
    string s;
    getline(cin,s);
    Solution ss;
    ss.isValid(s)?cout<<"True":cout<<"False";
    return 0;
}