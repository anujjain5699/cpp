#include<bits/stdc++.h>
using namespace std;
struct Node{
    int coeff,pow;
    Node* next;
};

Node* addNode(Node* head,int coeff,int pow)
{
    Node* new_node=new Node;
    new_node->coeff=coeff;
    new_node->pow=pow;
    new_node->next=NULL;

    if(head==NULL)
    return new_node;

    Node* ptr=head;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=new_node;
    return head;
}

void print(Node* head)
{
    while(head->next)
    {
        cout<<head->coeff<<"x^"<<head->pow<<" + ";
        head=head->next;
    }
    cout<<head->coeff<<"\n";
}

void removeDuplicate(Node* head)
{
    Node *ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1 && ptr1->next)
    {
        ptr2=ptr1;
        while(ptr2->next)
        {
            if(ptr1->pow==ptr2->next->pow)
            {
                ptr1->coeff=ptr1->coeff+ptr2->next->coeff;
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }
            else
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}

Node* multiply(Node* poly1,Node* poly2,Node* poly3)
{
    Node *ptr1,*ptr2;
    ptr1=poly1;
    ptr2=poly2;
    while(ptr1)
    {
        while(ptr2)
        {
            int coeff,pow;
            coeff=ptr1->coeff*ptr2->coeff;
            pow=ptr1->pow+ptr2->pow;
            poly3=addNode(poly3,coeff,pow);
            ptr2=ptr2->next;
        }
        ptr2=poly2;
        ptr1=ptr1->next;
    }
    removeDuplicate(poly3);
    return poly3;
}

int main()
{
    Node *poly1=NULL,*poly2=NULL,*poly3=NULL;
    poly1=addNode(poly1,3,2);
    poly1=addNode(poly1,5,1);
    poly1=addNode(poly1,6,0);
    poly1=addNode(poly1,6,0);
    //removing duplicate from polynomial also necessary
    removeDuplicate(poly1);
    poly2=addNode(poly2,6,1);
    poly2=addNode(poly2,12,1);
    poly2=addNode(poly2,8,0);
    removeDuplicate(poly2);
    cout<<"polynomial 1: ";
    print(poly1);
    cout<<"polynomial 2: ";
    print(poly2);
    poly3=multiply(poly1,poly2,poly3);
    cout<<"Resultant polynomial: ";
    print(poly3);
    return 0;
}