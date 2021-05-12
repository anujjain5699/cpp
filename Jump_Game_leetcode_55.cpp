/*
https://leetcode.com/problems/jump-game/*
solution: https://www.youtube.com/watch?v=muDPTDrpS28
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int reachable=0;
    for(int i = 0; i < n; i++){
        if(reachable<i){
            cout<<"false";
            res=1;
            break;
        }
        reachable=max(reachable,a[i]+i);
    }
    if(res==0)cout<<"true"<<endl;
    return 0;
}