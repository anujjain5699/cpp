#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n2)

Note that the above code modifies the given
 linked list and may not work if modifications 
 to linked list are not allowed. However we can
  finally do one more reverse to get original 
  list back.

*/



struct Node
{
    int data;
    struct Node* next;
};

Node *newNode(int key)
{
    Node* temp=new Node;
    temp->data=key;
    temp->next=NULL;
    return temp;
}

int countComman(Node* a,Node* b)
{
    int count=0;
    for(;a&&b;a=a->next,b=b->next)
    {
        if(a->data==b->data)
        count++;
        else
        break;
    }
    return count;
}

int maxPalindrome(Node *head)
{
    int result=0;
    Node *prev=NULL,*curr=head;

    while(curr)
    {
        Node *next=curr->next;
        curr->next=prev;

        // check for odd length palindrome 
        // by finding longest common list elements 
        // beginning from prev and from next (We 
        // exclude curr)
        result=max(2*countComman(prev,next)+1,result);

        // check for even length palindrome 
        // by finding longest common list elements 
        // beginning from curr and from next 
        result=max(2*countComman(curr,next),result);
        prev=curr;
        curr=next;
    }
    return result;
}

int main()
{
    Node *head = newNode(2); 
    head->next = newNode(4); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(2); 
    head->next->next->next->next->next = newNode(15); 
    cout << maxPalindrome(head) << endl;
    return 0;
}