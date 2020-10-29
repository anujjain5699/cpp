#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*
Input: 
            1     
          /   \
        2       3
      /  \     /  \
     4    5    6    7
    / \  / \  / \  / \ 
   8  9 3   1 4  2 7  2
     /     / \    \
    16    17  18   19
Output:
1
2 3
7 6 5 4
2 7 2 4 1 3 9 8
16 17 18 19
*/
struct Node 
{
    struct Node* left;
    int data;
    struct Node* right;
};

void modifiedLevelOrder(Node* root)
{
    if(root==NULL)
    return ;
    if(root->left==NULL&&root->right==NULL)
    {
        cout<<root->data;
        return;
    }
    queue<Node *> q;
    stack<Node *>s;
    struct Node* temp=NULL;
    int size;
    int count=0;
    bool righttoleft=false;
    q.push(root);
    while(!q.empty())
    {
        count++;
        size=q.size();
        for(int i=0;i<size;i++)
        {
            temp=q.front();
            q.pop();
            if(righttoleft==false)
            cout<<temp->data<<" ";
            else
            s.push(temp);
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        if(righttoleft==true)
        {
            while(!s.empty())
            {
                temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
            }
        }
        if(count==2)
        {
            righttoleft=!righttoleft;
            count=0;
        }
        cout<<"\n";
    }

}

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(2);
    root->left->right->left->left = newNode(16);
    root->left->right->left->right = newNode(17);
    root->right->left->right->left = newNode(18);
    root->right->right->left->right = newNode(19);
    modifiedLevelOrder(root);
    return 0;
}