#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int value;
};


Node *createNode(int x)
{
    Node *p = new Node;
    p->value = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(struct Node *root, int x)
{
    Node *p=root, *q=NULL;

    while (p!=NULL)
    {
        q = p;
        if (p->value < x)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }

    if (q == NULL)
        p = createNode(x);
    else
    {
        if (q->value < x)
        {
            q->right = createNode(x);
        }
        else
        {
            q->left = createNode(x);
        }
    }
}

// Return the maximum element between a Node
// and its given ancestor.
int maxelement(Node *q, int x)
{
    Node *p = q;

    int maximum=0;

    while (p->value != x)
    {
        if (p->value> x)
        {
            maximum = max(maximum, p->value);
            p = p->left;
        }
        else
        {
            maximum = max(maximum, p->value);
            p = p->right;
        }
    }

    return max(maximum, x);
}


int maximumElement(struct Node *root, int x, int y)
{
    Node *p = root;

    while ((x < p->value && y < p->value) || (x > p->value && y > p->value))
    {
        if (x < p->value && y < p->value)
            {
            p = p->left;
            }
        else if (x > p->value && y > p->value)
        {
            p = p->right;
        }
    }
    return max(maxelement(p, x), maxelement(p, y));
}


int main()
{
    int x;
    cin>>x;
    if(x==-1)
    {
        cout<<-1;
        return 0;
    }
    struct Node *root = createNode(x);
    while(1)
    {
        cin>>x;
        if(x == -1)
        {
            break;
        }
    insertNode(root,x);
    }
    int num;
    cin>>num;
    while(num--)
    {
    int a,b;
    cin>>a;
    cin>>b;
    cout << maximumElement(root,a,b) << endl;
    }
    return 0;
}

