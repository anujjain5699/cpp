#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;
   
};

void deleteDuplicate(Node** head_ref)
{

    if(*head_ref==NULL)
    return;
    Node* curr=*head_ref;
    while(curr->next!=NULL)
    {
        if(curr->next->data==curr->data){
            if(curr->next->next==NULL){
                Node* temp=curr->next;
                curr->next=NULL;
                free(temp);
                break;
            }
            else if(curr->next->next->data!=curr->data){
                Node* temp=curr->next;
                curr->next=curr->next->next;
                free(temp);
            }
        }
        curr=curr->next;
    }
}

void append(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    Node* last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    //if linked list is empty
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
    last=last->next;
    last->next=new_node;
    return ;
}
 void print(Node * n)
    {
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
        cout<<"\n";
    }
    int main()
    {
        Node* head=NULL;
        append(&head,100);
        append(&head,200);
        append(&head,300);
        append(&head,400);
        append(&head,500);
        append(&head,600);
        append(&head,700);
        append(&head,800);
        print(head);
        deleteDuplicate(&head);
        print(head);
        return 0;
    }