#include<bits/stdc++.h>
using namespace std;
int maxarea(vector<int> a,int n){
    stack<int> st;
    vector<int> left(n),right(n);
    for(int i=0;i<n;i++){
        if(st.empty()){
            left[i]=0;
            st.push(i);
        }else{
            while(!st.empty() && a[st.top()]>=a[i])
                st.pop();
            left[i]=st.empty()?0:st.top()+1;
            st.push(i);
        }
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            right[i]=n-1;
            st.push(i);
        }else{
            while(!st.empty() && a[st.top()]>=a[i])
            st.pop();
            right[i]=st.empty()?n-1:st.top()-1;
            st.push(i);
        }
    }
    int area=0;
    for(int i=0;i<n;i++){
        area=max(area,a[i]*(right[i]-left[i]+1));
    }
    return area;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxarea(v,n);
    return 0;
}