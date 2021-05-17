#include<bits/stdc++.h>
using namespace std;
void subsets(int a[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
        cout<<"\n";
    }
}
int main(){
    int a[]={1,2,3,4};
    subsets(a,4);
    return 0;
}