#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int value)
    {
        val=value;
        left=nullptr;
        right=nullptr;
    }
};
int height(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight+1);
        }
        else
        {
            return (rheight+1);
        }
    }
}

void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    //cout<<"h";
    if (!root)
    {
        root = node;
        return;
    }
    Node* prev = NULL;
    Node* temp = root;
    while (temp!=nullptr)
    {
        if (temp->val > key)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->val < key)
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->val > key)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }
}
int main()
{
    Node* root = NULL;
    int x;
    while(1)
    {
        cin>>x;
        if(x == -1)
        {
            break;
        }
        insert(root,x);
    }
    //printLevelOrder(root);
    cout<<height(root)-1;
    return 0;
}
