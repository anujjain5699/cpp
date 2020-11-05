#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
};
Node* newNode(int val)
{
    Node* node=new Node();
    node->data=val;
    node->left=node->right=NULL;
    return node;
}

void printLeft(Node* root)
{
    if(!root)
    return;
    if(root->left)
    {
        cout<<root->data<<" ";
        printLeft(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printLeft(root->right);
    }
}

void printRight(Node* root)
{
    if(!root)
    return;
    if(root->right)
    {
        cout<<root->data<<" ";
        printRight(root->right);
    }
    else if(root->left)
    {
        cout<<root->data<<" ";
        printRight(root->left);
    }
}

void printLeaves(Node* root)
{
    if(!root)
    return;
    if(root->right)
    printLeaves(root->right);
    if(!(root->left)&&!(root->right))
    cout<<root->data<<" ";
    printLeaves(root->left);
}

void printBoundary(Node* root)
{
    if(!root)
    return;
    cout<<root->data<<" ";
    printRight(root->right);
    printLeaves(root->right);
    printLeaves(root->left);
    printLeft(root->left);
}

int main()
{
    Node* root=newNode(20);
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25);
    printBoundary(root);
    return 0;
}