//https://www.youtube.com/watch?v=lGWLBgwd-cw
#include<bits/stdc++.h>
using namespace std;
vector<int> stock_span_problem(vector<int> a)
{
    stack<pair<int,int>> st;
    vector<int> ans;
    int n=a.size();
    for(auto price :a){
        int days=1;
        while(!st.empty() && st.top().first<=price){
            days+=st.top().second;
            st.pop();
        }
        st.push({price,days});
        ans.push_back(days);
    }
    return ans;
}
int main() {
    vector<int> a={100,80,60,70,60,75,85};
    vector<int> b=stock_span_problem(a);
    for(auto i:b)cout<<i<<" ";
    return 0;
}