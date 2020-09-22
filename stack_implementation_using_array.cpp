#include<bits/stdc++.h>
using namespace std;

#define Max 1000

class Stack{
    int top;

public:
    int a[Max];

    Stack(){
        top=-1;
    }

    bool push(int key);
    int pop();
    int peek();
    bool isEmpty();
    void printStack();
};


bool Stack::push(int x)
{
    if(top>=(Max-1))
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else
    {
        a[++top]=x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if(top<0)
    {
        cout<<"Stack underflow\n";
        return 0;
    }
    else
    {
        return a[top--];
    }
}

int Stack::peek()
{
    if(top<0)
    {
        cout<<"Stack underflow\n";
        return 0;
    }
    else
    {
        return a[top];
    }
}

bool Stack::isEmpty()
{
    return (top<0);
}


void Stack::printStack()
{
    if(isEmpty())
    return ;
    for(int i=0;i<=top;i++)
    {
        cout<<a[i]<<" ";
    }  
}

int main()
{
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<"Stack is empty : "<<(s.isEmpty()?"Yes":"No")<<endl;
    cout<<s.pop()<<" Popped from stack\n";
    cout<<"Stack : ";
    s.printStack();
    return 0;
}