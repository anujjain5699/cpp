#include<bits/stdc++.h>
using namespace std;
/*
Input : n = 4
              10
            /   \
           20     30
         /   \
        40     50
Output : 10
Inorder Traversal is : 40 20 50 10 30
*/
struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data = data; 
    node->left = NULL; 
    node->right = NULL;
    return(node);
}

void NthInorder(struct Node *root,vector<int> &v)
{
    if(root==NULL)
        return;
        NthInorder(root->left,v);
        v.push_back(root->data);
        NthInorder(root->right,v);
}


int main()
{
    struct Node* root=newNode(10);
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(50);
    int n = 1; 
    vector<int> v;
    NthInorder(root, v);
    if(v.size()<n||n==0)cout<<"Not possible";
    else
    {
        cout<<v.at(n-1);
    }
    
    return 0; 
}