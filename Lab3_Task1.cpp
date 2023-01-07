#include<bits/stdc++.h>
using namespace std;


struct node
{
    int val;
    node* next;
};

class Singly_linked_list
{
public:
    node *head, *tail;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }


    void pushback(int i)
    {
        node* new_node = new node();
        new_node->val = i;
        new_node->next = nullptr;
        if(head == nullptr)
        {

            head = new_node;
            return;
        }
        else
        {
            node* curr = head;

            while( curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = new_node;

        }
    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {
        node* current = head;
        node *prev = NULL;
        node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;

    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    Singly_linked_list a;
    for(int i =1 ; i < 10; i++)
    {
        a.pushback(i);
    }

    a.display();
    a.pushback(42);
    a.Reverse();
    a.pushback(100);
    a.display();
    return 0;
}
