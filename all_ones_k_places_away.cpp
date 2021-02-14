//https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int one_index=0;
        bool is_first_one=true;
        for(int i=0;i<nums.size();i++){
            if(is_first_one==true && nums[i]==1){
                one_index=i;
                is_first_one=false;
            }
            else if(nums[i]==1){
                if((i-one_index)>k){
                    one_index=i;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    int n;
    cout<<"Enter vector length : \n";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<"Enter k: \n";
    int k;
    cin>>k;
    Solution me;
    me.kLengthApart(v,k)?cout<<"True":cout<<"False";
    return 0;  
}