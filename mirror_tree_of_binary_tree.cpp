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

void mirrorify(Node* root,Node** mirror)
{
    if(root==NULL){
        mirror=NULL;
        return;
    }
    *mirror=newNode(root->data);
    mirrorify(root->left,&((*mirror)->right));
    mirrorify(root->right,&((*mirror)->left));
}

int main()
{
    Node* root=newNode(5);
    root->left=newNode(6);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->right=newNode(2);
    inorder(root);
    Node* mirror=NULL;
    mirrorify(root, &mirror);
    cout<<"\nmirror tree: ";
    inorder(mirror);
    return 0;
}