#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

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

Node* pairWiseSwap(Node* head)
{
    if(head==NULL|| head->next==NULL)
    return head;

    Node* remain=head->next->next;
    Node* new_head=head->next;
    head->next->next=head;
    head->next=pairWiseSwap(remain);
    return new_head;
}

int main()
{
    Node *head=NULL;
    append(&head,9);
    append(&head,8);
    append(&head,7);
    append(&head,6);
    append(&head,5);
    append(&head,4);
    append(&head,3);
    append(&head,2);
    append(&head,1);
    print(head);
    cout<<"\nAfter Swap: \n";
    head=pairWiseSwap(head);
    print(head);
    return 0;
}