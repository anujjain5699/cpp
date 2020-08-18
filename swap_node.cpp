#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;
    
    Node(int val,Node* next):data(val),next(next){}
};

void swap(Node*& a,Node*& b)
{
    Node* temp=a;
    a=b;
    b=temp;
}

void swapNodes(Node** head_ref,int x,int y)
{
    if(x==y)
    return;
    Node **a=NULL,**b=NULL;
    while(*head_ref)
    {
        if((*head_ref)->data==x)
        a=head_ref;
        else if((*head_ref)->data==y)
        b=head_ref;
        head_ref=&((*head_ref)->next);
    }
    if(a&&b)
    {
        swap(*a,*b);
        swap(((*a)->next),((*b)->next));
    }
}

void push(Node** head_ref,int new_data)
{
    *head_ref=new Node(new_data,*head_ref);
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    Node* head=NULL;
    
    // The constructed linked list is: 
    // 1->2->3->4->5->6->7 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 

    cout<<"LinkedList before calling swapNode(): ";
    print(head);
    swapNodes(&head,6,3);
    cout<<"\nLinkedList after calling swapNode(): ";
    print(head);
}