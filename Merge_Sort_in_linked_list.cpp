#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

Node* sortedMerge(Node* a, Node* b); 

void FrontBackSplit(Node* head,Node **first,Node **second)
{
    Node* fast;
    Node* slow;
    slow=head;
    fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=head;
    *second=slow->next;
    slow->next=NULL;
}

void mergeSort(Node **head_ref)
{
    Node *head=*head_ref;
    Node *first;
    Node *second;

    if(head==NULL||head->next==NULL)
    return;

    FrontBackSplit(head,&first,&second);

    mergeSort(&first);
    mergeSort(&second);

    *head_ref=sortedMerge(first,second);
}


Node* sortedMerge(Node *first,Node *second)
{
    Node *result=NULL;

    if(first==NULL)
    return (second);

    else if(second==NULL)
    return (first);

    if(first->data <= second->data)
    {
        result=first;
        result->next=sortedMerge(first->next,second);
    }
    else{
        result=second;
        result->next=sortedMerge(first,second->next);
    }
    return (result);
}

void append(Node** head,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    Node* last=*head;
    while(last->next!=NULL)
    last=last->next;
    last->next=new_node;
    return;
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
    Node *head=NULL;
    append(&head,9);
    append(&head,5);
    append(&head,70);
    append(&head,4);
    append(&head,12);
    append(&head,14);
    append(&head,11);
    append(&head,21);
    append(&head,1);
    print(head);
    mergeSort(&head);
    cout<<"\nSorted LinkedList is: "<<endl;
    print(head);
    return 0;
}