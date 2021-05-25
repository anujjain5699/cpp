#include<bits/stdc++.h>
using namespace std;

int findLong(string s)
{
    int n=s.length();
    int start=-1,ans=0;
    vector<int> a(256,-1);
    for(int i=0;i<n;i++)
    {
        if(a[s[i]]>start)
        start=a[s[i]];
        a[s[i]]=i;
        ans=max(ans,i-start);
    }
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    cout<<findLong(s);
    return 0;
}