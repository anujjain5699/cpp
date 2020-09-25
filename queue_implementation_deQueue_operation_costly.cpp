#include<bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int> s1,s2;

    void enQueue(int x){
        s1.push(x);
    }

    int deQueue(){
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue is empty \n";
            exit(0);
        }
        if(s2.empty()){
            while(!(s1.empty())){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(13); 
    q.enQueue(21); 
    q.enQueue(34); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    return 0;
}