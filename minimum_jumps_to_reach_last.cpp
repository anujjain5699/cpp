#include<bits/stdc++.h>
using namespace std;
int jumps(int arr[],int n)
{
    if(n==1)return 0;
    int ans=1;
    int max_reach=arr[0];
    int curr=arr[0];
    int i=1;
    while(max_reach<n-1)
    {
        if(i+arr[i]>curr)curr=i+arr[i];
        if(max_reach<curr)
        {
            max_reach=curr;
            ans++;
        }
        i++;
    }
    return ans;
}
int main()
{
    int arr[] = { 1, 3, 6, 3, 2,3, 6, 8, 9, 5 };
    //int arr[]={3,3,0,2,1,2,4,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<jumps(arr,n);
    return 0;
}