
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};


struct node* newnode(int item)
{
    struct node* temp;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node*& root, int key)
{
    node* node = new newnode(key);
    //cout<<"h";
    if (!root)
    {
        root = node;
        return;
    }
    node* prev = NULL;
    node* temp = root;
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

struct node* minValuenode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(node* node)
{
    if (node == NULL)
        return 0;
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
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
    }
}

struct node* deletenode(struct node* root, int data)
{
    if (root == NULL)
        {
            return root;}


    if (data < root->data)
        {root->left = deletenode(root->left, data);}


    else if (data > root->data)
        {root->right = deletenode(root->right, data);}


    else
    {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            {return NULL;}

        // node with only one child or no child
        else if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValuenode(root->right);

        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{

    struct node* root = NULL;
    int x;
    cin>>x;
    if(x==-1)
    {
        return 0;
    }
    root = insert(root, x);
    cout<<x;
    while(1)
    {
        cin>>x;
        cout<<x;
        if(x==-1)
        {
            break;
        }
    root = insert(root, x);
    }
    int n;
    cin>>n;
    while(n--)
          {
                int z;
    cin>>z;
    root = deletenode(root, z);
    printLevelOrder(root);
          }
    return 0;
}
