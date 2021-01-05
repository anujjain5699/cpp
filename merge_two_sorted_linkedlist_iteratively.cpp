#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;
   
};

Node* mergelist(Node* head1,Node* head2)
{
    Node* ptr1=new Node();
    if(head1==NULL && head2==NULL)return ptr1;
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    if(head1->data < head2->data){
        ptr1=head1;
        head1=head1->next;
    }
    else{
        ptr1=head2;
        head2=head2->next;
    }
    Node* ptr=ptr1;
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            ptr->next=head1;
            head1=head1->next;
        }
        else{
            ptr->next=head2;
            head2=head2->next;
        }
        ptr=ptr->next;
    }
    if(head1!=NULL){
        while(head1){
            ptr->next=head1;
            ptr=ptr->next;
            head1=head1->next;
        }
    }
    if(head2!=NULL){
        while(head2){
            ptr->next=head2;
            ptr=ptr->next;
            head2=head2->next;
        }
    }
    return ptr1;
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
        Node* head1=NULL;
        append(&head1,100);
        append(&head1,210);
        append(&head1,300);
        append(&head1,450);
        append(&head1,520);
        append(&head1,630);
        append(&head1,700);
        append(&head1,800);
        Node* head2=NULL;
        append(&head2,100);
        append(&head2,200);
        append(&head2,300);
        append(&head2,400);
        append(&head2,500);
        append(&head2,600);
        append(&head2,650);
        append(&head2,900);
        print(head1);
        print(head2);
        Node* ptr=new Node();
        ptr=mergelist(head1,head2);
        print(ptr);
        return 0;
    }
