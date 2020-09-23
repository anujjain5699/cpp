#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(1)

void showstack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<"\n";
}

int main()
{
    stack<int> s;
    s.push(1),
    s.push(2),
    s.push(3),
    s.push(4),
    s.push(5),
    s.push(6),
    cout<<"Stack : ";
    showstack(s);
    cout<<"Stack size : "<<s.size()<<endl;
    cout<<"Stack top : "<<s.top()<<endl;
    cout<<(s.empty()?"Stack empty":"Stack not empty")<<endl;
    /*
    Time Complexity : O(1)

    Difference between stack::emplace() and stack::push() function.
    push() function inserts a copy of the value or the parameter 
    passed to the function into the container at the top, the emplace()
    function constructs a new element as the value of the parameter 
    and then adds it to the top of the container.
    
    */
    s.emplace(9);
    cout<<"Stack : ";
    showstack(s);

    stack<int> s1,s2;

    s1.push(1),
    s1.push(2),
    s1.push(3),
    s1.push(4),
    s1.push(5),
    s1.push(6),

    s2.push(11),
    s2.push(12),
    s2.push(13),
    s2.push(14),
    s2.push(15),
    s2.push(16),

    cout<<"------------------------------"<<endl;
    cout<<"\nStack 1 : ";
    showstack(s1);
    cout<<"Stack 2 : ";
    showstack(s2);

    cout<<"\n----After swap stack 1 & 2----"<<endl;
    s1.swap(s2);
    cout<<"\nStack 1 : ";
    showstack(s1);
    cout<<"Stack 2 : ";
    showstack(s2);


    return 0;
}