#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
};
node* newnode(int val)
{
    node* ptr=new node();
    ptr->data=val;
    ptr->right=NULL;
    ptr->left=NULL;
    return(ptr);
}

void printArray(int ints[], int len)  
{  
    int i;  
    for (i = 0; i < len; i++)  
    {  
        cout << ints[i] << " ";  
    }  
    cout<<endl;  
}  

void paths(node *root,int path[],int pathlen)
{
    if(root==NULL)
    return;

    path[pathlen]=root->data;
    pathlen++;

    if(root->left==NULL&&root->right==NULL)
    {
        printArray(path,pathlen);
    }
    else{
        paths(root->left,path,pathlen);
        paths(root->right,path,pathlen);
    }
}

void printPaths(node *root)
{
    int path[1000];
    paths(root,path,0);
}

int main()
{
    node* root=newnode(10);
    root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);
    root->left->right->right = newnode(6);
    root->left->right->left = newnode(7);
    root->right->left = newnode(2);
    printPaths(root);
    return 0;
}