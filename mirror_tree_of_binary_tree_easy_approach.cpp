#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
};
Node* newNode(int val){
    Node* node=new Node();
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
    inorder(root->left); 
    printf("%d ", root->data); 
    inorder(root->right); 
}

void mirrorify(Node* root)
{
    if(!root)return;
    mirrorify(root->left);
    mirrorify(root->right);
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}

int main()
{
    Node* root=newNode(5);
    root->left=newNode(6);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->right=newNode(2);
    inorder(root);
    //Node* mirror=NULL;
    mirrorify(root);
    cout<<"\nmirror tree: ";
    inorder(root);
    return 0;
}