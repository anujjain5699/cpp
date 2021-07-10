#include<bits/stdc++.h>
using namespace std;
bool istriplet(int *a,int n)
{
    int max_element=INT_MIN;
    for(int  i=0;i<n;i++)max_element=max(max_element,a[i]);
    int hash[max_element+1]={0};
    for(int i=0;i<n;i++)hash[a[i]]++;
    int val=0;
    for(int i=1;i<n;i++)
    {
        if(hash[i]==0)continue;
        for(int j=1;j<n;j++)
        {
            if((i==j &&hash[i]==1) || hash[i]==0)continue;
            val=sqrt(i*i+j*j);
            if(val*val!=(i*i+j*j))continue;
            if(val>max_element)continue;
            if(hash[val])
            {
                cout<<"triplet : "<<i<<" "<<j<<" "<<val<<endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a[]={3,1,2,4,8};
    int n=sizeof(a)/sizeof(a[0]);
    if(istriplet(a,n)==false)cout<<"Not found";
    return 0;
}