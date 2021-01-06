/*
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences),
leaving only numbers that appear once in the original list. 
Examples:

Input : 23->28->28->35->49->49->53->53
Output : 23->35

Input : 11->11->11->11->75->75
Output : empty List
*/


#include <bits/stdc++.h> 
using namespace std; 
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  

void removeDuplicates(Node* &head)  
{
    Node* dummy=new Node();
    Node* prev=dummy;
    dummy->next=head;
    Node* curr=head;
    while(curr){
        while(curr->next!=NULL && prev->next->data==curr->next->data)
        curr=curr->next;
        if(prev->next==curr)
        prev=prev->next;
        else
        prev->next=curr->next;
        curr=curr->next;
    }
    head=dummy->next;
}  

void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);      
    (*head_ref) = new_node;  
}  

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  

int main()  
{
    Node* head = NULL; 
    push(&head, 21); 
    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 11);  
    push(&head, 11);  
    push(&head, 11); 
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);                                     
    cout<<"Linked list before duplicate removal ";  
    printList(head);  
    removeDuplicates(head);  
    cout<<"\nLinked list after duplicate removal ";      
    printList(head);              
    return 0;  
}  
  