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
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
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
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->val << " ";
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {

        printCurrentLevel(root, i);
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
    printLevelOrder(root);
    return 0;
}
