#include <bits/stdc++.h> 
using namespace std; 


class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

Node *reverse (Node *head, int k) 
{ 
	Node* current = head; 
	Node* next = NULL; 
	Node* prev = NULL; 
	int count = 0; 
	while (current != NULL && count < k) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
		count++; 
	}
	if (head != NULL) 
	head->next = current; 
    count=0;
    while(count<k-1&&current!=NULL){
        current=current->next;
        count++;
    }
    if(current!=NULL)current->next=reverse(current->next,k);
	return prev; 
} 

void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref);	 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

int printList(Node *node) 
{ 
  int count=0;
	while (node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
      count++;
	} 
  return count;
} 

int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 11);
    push(&head, 12); 
	push(&head, 13);
    push(&head, 14);
    push(&head, 15);	 
    int k;
	cout<<"Given linked list \n"; 
    /*
    Length of linked list is calculated inside the printList function 
    otherwise we have to make separate function for length calculation
    */
	int length=printList(head); 
    cout<<"\nEnter the group length: ";
    cin>>k;
	head = reverse(head, k); 
	cout<<"\nReversed Linked list \n"; 
	length=printList(head); 
	return(0); 
} 
