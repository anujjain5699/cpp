/* CPP program to print levels  
line by line */
#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct node 
{ 
    struct node *left; 
    int data; 
    struct node *right; 
}; 

void levelorder(node* root)
{
    if(root==NULL)
    return;
    
    queue<node *>q;
    node *front;
    q.push(root);
    q.push(NULL);

    while(q.size()>1)
    {
        front=q.front();
        q.pop();
        if(front==NULL)
        {
            q.push(NULL);
            cout<<"\n";
        }
        else
        {
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
            cout<<front->data<<" ";
        }
        
    }

}

node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 

int main() 
{ 
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    levelorder(root); 
    return 0; 
} 