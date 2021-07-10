#include<bits/stdc++.h>
using namespace std;
bool subset_sum(int a[],int sum,int n)
{
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            if(i==0 && j==0)dp[i][j]=true;
            else if(i==0)dp[i][j]=false;
            else if(j==0)dp[i][j]=true;
            else
            {
                if(dp[i-1][j]==true)dp[i][j]=true;
                else
                {
                    int val=a[i-1];
                    if(j>=val)
                    {
                        if(dp[i-1][j-val]==true)dp[i][j]=true;
                    }                   
                }
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int a[]={3,4,-7,3,1,3,1,-4,-2,-2};
    int sum=0;
    int n=sizeof(a)/sizeof(a[0]);
    if(subset_sum(a,sum,n)==true)cout<<"Yes";
    else cout<<"No";
    return 0;
}