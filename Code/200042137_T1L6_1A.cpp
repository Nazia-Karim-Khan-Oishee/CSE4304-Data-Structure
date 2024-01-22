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
bool check(Node*& root, int key)
{
    Node* temp = root;
    Node* temp2 = root;
    while (temp!=nullptr)
    {
        if (abs(temp->val - key)<=3)
        {
            //cout<<"H";
            return true;
        }
        temp = temp->left;
    }
    while (temp2!=nullptr)
    {
        if (abs(temp2->val - key)<=3)
        {
            return true;
        }
        temp2 = temp2->right;
    }
    return false;
}
void InOrder(Node *root)
{
    Node* temp=root;
    if(temp != NULL)
    {
        InOrder(temp->left);
        cout << temp->val << " ";
        InOrder(temp->right);
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
        //insert(root,x);

        bool within_range=check(root,x);
        if(!within_range)
        {
            insert(root,x);
            InOrder(root);
        }
        else
        {
            InOrder(root);
            cout<<"(Reservation failed)"<<endl;
        }

       // InOrder(root);
    }
        return 0;
    }
