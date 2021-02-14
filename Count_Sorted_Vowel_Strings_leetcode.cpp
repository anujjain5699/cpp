//https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3607/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char ch[5]={'a','e','i','o','u'};
    int count(int length,char last_char){
        if(length==0)return 1;
        int temp=0;
        for(char c:ch){
            if(last_char>=c){
                temp+=count(length-1,c);
            }
        }
        return temp;
    }
    int countVowelStrings(int n) {
        int ans=0;
        for(char c:ch){
            ans+=count(n-1,c);
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    n=s.countVowelStrings(n);
    cout<<n;
    return 0;
}