#include<bits/stdc++.h>
using namespace std;
/*
Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
          \
           8
Output : Product  = 36, Sum = 12
Non-leaf nodes are: 1, 2, 3, 6 
*/
class node{
    public:
    int data;
    node* left,*right;
};

node* newnode(int val)
{
    node* Node=new node();
    Node->data=val;
    Node->left=NULL;
    Node->right=NULL;
    return(Node);
}

void traversal(node* root,int& sum,int& product){
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    return;
    sum+=root->data;
    product*=root->data;
    traversal(root->left,sum,product);
    traversal(root->right,sum,product);
}

int main()
{
    node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->right->left->right=newnode(8);
    int sum=0,product=1;
    traversal(root,sum,product);
    cout<<"Sum: "<<sum<<"\n";
    cout<<"Product: "<<product;
    return 0;
}