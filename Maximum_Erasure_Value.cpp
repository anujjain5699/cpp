//https://www.youtube.com/watch?v=Hx8Nh5_THt0
#include<bits/stdc++.h>
using namespace  std;

int findMax(vector<int> a)
{
    int n=a.size();
    vector<int> p(n+1,0);
    vector<int> m(10001,-1);
    for(int i=0;i<n;i++){
        p[i+1]=p[i]+a[i];
    }
    int start=0,ans=0;
    for(int i=0;i<n;i++){
        start=max(start,m[a[i]]+1);
        ans=max(ans,p[i+1]-p[start]);
        m[a[i]]=i;
    }
    return ans;
}
int main(){
    vector<int> v={5,2,2,5,5,1,18,1,2};
    cout<<findMax(v);
}