#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node* pre;
};

void push(Node** head,int new_data)
{
    
    Node* temp=new Node();
    temp->data=new_data;
    temp->next=*head;
    if((*head)!=NULL)
    (*head)->pre=temp;
    (*head)=temp;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void reverseList(Node** head)
{
    Node* curr=*head;
    Node* temp=NULL;

    while(curr!=NULL)
    {
        temp=curr->pre;
        curr->pre=curr->next;
        curr->next=temp;
        curr=curr->pre;
    }
    if(temp!=NULL)
    (*head)=temp->pre;
}

/*
    Time Complexity: O(n)
*/
int main()
{
    Node* head=NULL;
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    cout<<"Original list: "<<endl;
    print(head);
    reverseList(&head);
    cout<<"\nNew list: "<<endl;
    print(head);
    return 0;
}