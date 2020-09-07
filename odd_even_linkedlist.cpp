/*
 Rearrange the given linked list so that all
the even indexed nodes comes to left and
all odd indexed elements goes to the right of
the linked list. This is basically a segregation task to
be performed on a linked list.We are also not allowed 
to use any extra space and we need to
solve it in just O(N) time complexity.

*/


#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int data;
    Node* next;
};

void push(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void print(Node * n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

Node* oddevenList(Node* head)
{
    if(!head)
    return(head);

    Node* end=head;
    Node* temp=head;
    int count=0;

    while(end->next)
    {
        count++;
        end=end->next;
    }
    
    count=count%2!=0?(count/2)+1:count;

    while(--count)
    {
        end->next=temp->next;
        temp->next=temp->next->next;
        end->next->next=NULL;
        end=end->next;
        temp=temp->next;
    }
    return head;
}

/*
TIME COMPLEXITY O(N)
*/


int main()
{
    Node* head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,8);
    push(&head,10);
    push(&head,7);
    push(&head,9);
    print(head);
    cout<<endl;
    oddevenList(head);
    print(head);
    return 0;
}