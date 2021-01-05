#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

Node* newNode(int val)
{
    Node* node=new Node();
    node->data=val;
    node->next=NULL;
    return node;
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
	while (node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
	}
} 

void add(Node** head,int n){
    Node* curr=newNode(n);
    if(*head==NULL || (*head)->data>=n){
    curr->next=*head;
    *head=curr;
    }
    else{
        Node* temp=*head;
    while(temp->next->data < n&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=curr;
    }
}

int main()
{
    Node* head = NULL; 
	push(&head, 15);
    push(&head, 14); 
	push(&head, 13);
    push(&head, 12);
    push(&head, 11);
    push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	//push(&head, 3); 
	push(&head, 2); 
	//push(&head, 1); 
    printList(head);
	cout<<"\nenter number :";
    int n;
    cin>>n;
    add(&head,n);
    printList(head);
    return 0;
}