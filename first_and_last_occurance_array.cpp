#include <bits/stdc++.h>
using namespace std;
int firstoccurrence(int a[],int n,int i,int k){
    if(i==n){
        return -1;
    }
    if(a[i]==k){
        return i;
    }
    return firstoccurrence(a,n,i+1,k);
}

int lastoccurrence(int a[],int n,int i,int k){
    
    if(i==n)return -1;

    int res=lastoccurrence(a,n,i+1,k);

    if(res!=-1)return res;
    if(a[i]==k)return i;

    return -1;

}

int main(){
    int a[]={2,4,6,8,3,4,6,7,3,1};
    cout<<firstoccurrence(a,10,0,3)<<endl;
    cout<<lastoccurrence(a,10,0,3)<<endl; 
    return 0;
}