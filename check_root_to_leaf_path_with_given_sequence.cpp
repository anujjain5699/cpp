#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr);
    ~Node();
};

int main()
{
    vector<int> v={2,5,8,32,4,21};
    int s=v.size();
     Node *root = new Node(5); 
    root->left =  new Node(3); 
    root->right =  new Node(8); 
    root->left->left =  new Node(2); 
    root->left->right =  new Node(4); 
    root->left->left->left = new Node(1); 
    root->right->left =  new Node(6); 
    root->right->left->right =  new Node(7); 
    exitPath(root,arr,n,0)?cout<<"Path Exists":cout<<"Path does not Exist";
    return 0; 
}