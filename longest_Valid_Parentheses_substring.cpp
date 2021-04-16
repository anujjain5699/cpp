/*
https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3695/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),count=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            char x=s[i];
            if(x=='(')st.push(i);
            else{
                st.pop();
                if(st.empty())st.push(i);
                else{
                    int l=i-st.top();
                    count=max(count,l);
                }
            }
        }
        return count;
    }
};
int main(){
    string s;
    getline(cin,s);
    Solution ss;
    cout<<ss.longestValidParentheses(s);
return 0;
}
