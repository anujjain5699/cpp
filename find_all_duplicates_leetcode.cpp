/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> find_dup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int j=0,i=1;
        for(;i<=nums.size() ;i++)
        {
            if(j<nums.size() && i==nums[j])
            {
                int temp=nums[j],count=1;
                j++;
                while(j<nums.size() && count>0)
                {
                    if(temp==nums[j])
                    {
                        j++;
                        count--;
                         v.push_back(temp);
                    }
                    else break;
                }
            }
        }
        return v;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    Solution me;
    vector<int> nn=me.find_dup(v);
    for(auto i:nn)cout<<i<<" ";
    return 0;  
}
