//https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
#include<bits/stdc++.h>
using namespace std;
void find_triplet_equal_target(vector<int> a,int target){
    int n=a.size();
    int flag=0;
    int l,r;
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==target){
                flag=1;
                cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<endl;
                return ;
            }
            else if(a[i]+a[l]+a[r]>target)r--;
            else l++;
        }
    }
    if(flag==0)cout<<"Triplet not found\n";
    return;
}
int main(){
    vector<int> a={ 1, 4, 45, 6, 10, 8 };
    int target=2;
    find_triplet_equal_target(a, target);
    return 0;
}
