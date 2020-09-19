#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;

        if(arr[mid]==x)
        return mid;

        if(arr[mid]>x)
        return binarySearch(arr,l,mid-1,x);

        return binarySearch(arr,mid+1,r,x);
    }
    return -1;
}

int main()
{
    /*necessarily array should be sorted if 
    array is not sorted firstly sort it*/
    int arr[]={2,4,6,9,12,15,19};
    int x=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=binarySearch(arr,0,n-1,x);
    (result==-1)?cout<<"Element not found":cout<<"Element is present at index : "<<result;
    return 0;
}