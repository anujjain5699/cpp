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

bool isPalindrome(Node* head)
{
     Node* temp=head;
    stack<int> s;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int i=s.top();
        s.pop();
        if(head->data!=i)
        return false;
        head=head->next;
    }
    return true;
}

int main()
{
        Node* head=NULL;
        push(&head,1);
        push(&head,2);
        push(&head,5);
        push(&head,4);
        push(&head,2);
        push(&head,1);
        if(isPalindrome(head))
        cout<<"Yes";
        else
        cout<<"No";
        return 0;
    }