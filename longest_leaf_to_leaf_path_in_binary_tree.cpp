#include <bits/stdc++.h> 
using namespace std; 
 // Enter the binary tree ... 
    //           1 
    //         /   \      
    //        2     3 
    //      /   \    
    //     4     5 
    //      \   / \  
    //       8 6   7 
    //      / 
    //     9
class node
{
    public:
    int data;
    node *left;
    node *right;
};
node* newnode(int val)
{
    node* Node=new node();
    Node->data=val;
    Node->left=NULL;
    Node->right=NULL;
    return(Node);
}

int height(node *root,int& ans,node*(&k),int& lh,int& rh,int& f)
{
    if(root==NULL)
    return 0;
    int left_height=height(root->left,ans,k,lh,rh,f);
    int right_height=height(root->right,ans,k,lh,rh,f);
    if(ans<1+left_height+right_height)
    {
        ans=1+left_height+right_height;
        k=root;
        lh=left_height;
        rh=right_height;
    }
    return 1+max(left_height, right_height);
}

void printArray(int ints[], int len, int f) 
{ 
    int i; 
    if (f == 0) { 
        for (i = len - 1; i >= 0; i--) { 
            printf("%d ", ints[i]); 
        } 
    }   
    else if (f == 1) { 
        for (i = 0; i < len; i++) { 
            printf("%d ", ints[i]); 
        } 
    } 
} 

void printPathRecur(node *root,int path[],int pathlen,int max,int& f)
{
    if(root==NULL)
    return;
    path[pathlen]=root->data;
    pathlen++;
    if(root->left==NULL&&root->right==NULL)
    {
        if(pathlen==max&&(f==0||f==1))
        {
            printArray(path,pathlen,f);
            f=2;
        }
    }
    else{
        printPathRecur(root->left,path,pathlen,max,f);
        printPathRecur(root->right,path,pathlen,max,f);
    }
}

void diameter(node *root)
{
    if(root==NULL)
    return;
    int ans=INT_MIN,lh=0,rh=0;
    int f=0;
    node* k;
    int height_of_tree=height(root,ans,k,lh,rh,f);
    int lpath[100],pathlen=0;
    printPathRecur(k->left,lpath,pathlen,lh,f);;
    printf("%d ",k->data);
    int rpath[100];
    f=1;
    printPathRecur(k->right,rpath,pathlen,rh,f);
    
}

int main()
{
    node* root=newnode(1);
    root->left = newnode(2); 
    root->right = newnode(3); 
    root->left->left = newnode(4); 
    root->left->right = newnode(5); 
    root->left->right->left = newnode(6); 
    root->left->right->right = newnode(7); 
    root->left->left->right = newnode(8); 
    root->left->left->right->left = newnode(9);
    diameter(root);
    return 0;
}