/*
Problem
Given an array arr[] of size N. The task is to find the first repeating element in an
array of integers, i.e., an element that occurs more than once and whose index of
first occurrence is smallest.
Constraints
1 <= N <= 106
0 <= Ai <= 106
Example
Input:
7
1 5 3 4 3 5 6
Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int N=1e6+2;
    int inx[N];
    for(int i=0;i<N;i++){inx[i]=-1;}
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(inx[a[i]]!=-1){
            mini=min(mini,inx[a[i]]);
        }
        else{
            inx[a[i]]=i;
        }
    }
    if(mini==INT_MAX){
        cout<<"-1\n";
    }else{
        cout<<(mini)<<"\n";
    }
    return 0;
}