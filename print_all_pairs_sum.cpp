//https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/
#include<bits/stdc++.h>
using namespace std;
void pairsum(int *a,int sum,int n)
{
    sort(a,a+n);
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==sum)
        {
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;
        }
        if(a[i]+a[j]>sum)j--;
        else i++;
    }
}
int main()
{
    int a[]={2,3,4,-2,6,8,9,11};
    int sum=6;
    int n=sizeof(a)/sizeof(a[0]);
    pairsum(a,sum,n);

}