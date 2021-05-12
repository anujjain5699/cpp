#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n){
    int currsum=0,maxi=INT_MIN;
    //apply kadane's algo
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0)currsum=0;
        maxi=max(maxi,currsum);
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int nonwrap=kadane(a,n),total=0;
    for(int i=0;i<n;i++){
        total+=a[i];
        a[i]=-a[i];
    }
    int wrap=total+kadane(a,n);
    cout<<max(wrap,nonwrap);
}