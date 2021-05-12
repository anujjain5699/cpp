//https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3607/
/*
time complexity=O(5*n)
space =O(6*n)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countVowelStrings(int n) {
       int dp[n+1][6];
        memset( dp, 0,(n+1)*6*sizeof(int) );
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                dp[i][j]=(i>1?dp[i-1][j]:1)+dp[i][j-1];
            }
        }
        return dp[n][5];
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