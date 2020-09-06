#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node* pre;
};

void append(Node** head,int new_data)
{
    Node* new_node=new Node();
    Node* last=*head;
    new_node->data=new_data;
    new_node->next=NULL;

    if(*head==NULL)
    {
        new_node->pre=NULL;
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    last=last->next;

    last->next=new_node;
    new_node->pre=last;
    return;
}

void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void push(Node** head,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->pre=NULL;
    new_node->next=*head;
    
    if((*head)!=NULL)
    (*head)->pre=new_node;

    (*head)=new_node;
}

void insertBefore(Node** head,Node* ptr,int new_data)
{
    if(ptr==NULL)
    {
        cout<<"next node cannot be NULL";
        return;
    }
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=ptr;
    new_node->pre=ptr->pre;
    ptr->pre=new_node;
    if(ptr->pre!=NULL)
    new_node->pre->next=new_node;
    else
    (*head)=new_node;
}

void insertAfter(Node* pre_node,int new_data)
{
    if(pre_node==NULL)
    {
        cout<<"previous node cannot be NULL";
        return;
    }

    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=pre_node->next;
    new_node->pre=pre_node;
    pre_node->next=new_node;

    if(new_node->next!=NULL)
    new_node->next->pre=new_node;
}


int main()
{
    Node* head=NULL;
    append(&head,7);
    append(&head,8);
    append(&head,9);
    append(&head,10);
    append(&head,11);
    append(&head,12);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
   insertAfter(head->next->next,20);
    insertBefore(&head,head->next,22);
    print(head);
    return 0;
}