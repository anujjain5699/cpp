#include<iostream>
#include<stack>
using namespace std;
void insertAtButtom(stack<int>&st,int buttom_element){
    if(st.empty()){
        st.push(buttom_element);
        return;
    }
    int top_element=st.top();
    st.pop();
    insertAtButtom(st,buttom_element);
    st.push(top_element);
}
void reverse(stack<int>& st){
    if(st.empty())
    return;

    int top_element = st.top();
    st.pop();
    reverse(st);
    insertAtButtom(st, top_element);
}
void printstack(stack<int> st){
    while(!st.empty()){
        cout << st.top()<<" ";
        st.pop();
    }
    return;
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printstack(st);
    reverse(st);
    cout<<"\nStack :\n";
    printstack(st);
    return 0;
}