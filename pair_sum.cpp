#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int i=0,j=n-1;
    while(i<j){
        if((a[i]+a[j]>k))j--;
        else if((a[i]+a[j])<k)i++;
        else if((a[i]+a[j])==k){
            cout<<i<<" "<<j;
            break;
        }
    }
    return 0;
}