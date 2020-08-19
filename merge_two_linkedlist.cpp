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

void print(Node* head_ref)
{
    Node* temp=head_ref;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* sortedMerge(Node* a,Node* b)
{
    Node* res=NULL;

    if(a==NULL)
    return(b);
    else if(b==NULL)
    return(a);
    
    if((a->data)<=(b->data))
    {
        res=a;
        res->next=sortedMerge(a->next,b);
    }
    else
    {
        res=b;
        res->next=sortedMerge(a,b->next);
    }
    return(res);
}

Node* removeDuplicate(Node *head)
{
    Node* p=head;
    Node* q;
    /*
    both condition to be checked
    example- 1->null,null,1->2->3->3->3->null
    */
    while(p!=NULL&&p->next!=NULL)
    {
        if(p->data==p->next->data)
        {
            q=p->next->next;
            if(q==NULL)
            {
                p->next=NULL;
                break;
            }
            p->next=q;
        }
        if(p->data!=p->next->data)
        p=p->next;
    }
    return head;
}

int main()
{
    Node* res=NULL;
    Node* a=NULL;
    Node* b=NULL;
    push(&a,6);
    push(&a,6);
    push(&a,5);
    push(&a,1);
    push(&b,10);
    push(&b,8);
    push(&b,7);
    push(&b,6);
    push(&b,3);
    cout<<"print a: "<<endl;
    print(a);
    cout<<"\nprint b: "<<endl;
    print(b);
    //remove duplicate
    a=removeDuplicate(a);
    b=removeDuplicate(b);
    cout<<"\nremove duplicate from a: "<<endl;
    print(a);
    cout<<"\nremove duplicate from b: "<<endl;
    print(b);
    res=sortedMerge(a,b);
    cout<<"\nprint result: "<<endl;
    print(res);
    res=removeDuplicate(res);
    cout<<"\nremove duplicate from result: "<<endl;
    print(res);
    return 0;
}