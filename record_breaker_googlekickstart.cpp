/*https://codingcompetitions.withgoogle.com
/kickstart/round/000000000019ff08/0000000000387171*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    a[n]=-1;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==1){
        cout<<"1\n";
        return 0;
    }
    int ans=0,mx=-1;
    for(int i=0;i<n;i++){
        if(a[i]>mx &&a[i]>a[i+1]){
            ans++;
            mx=max(a[i],mx);
        }
    }
    cout<<ans<<"\n";
    return 0;
}