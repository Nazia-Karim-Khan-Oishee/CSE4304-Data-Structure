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

    void printfromMiddle(int i)
    {
        node* temp = head;
        //int len = i;
        int len = i / 2;
       //cout<<len;
        while (len--)
        {
            temp = temp->next;
            //cout<<temp->val<<" ";

            /*if(len == 1)
            {
                break;
            }*/

        }
                   // cout<<temp->val<<" ";

        while (1)
        {
            cout<<temp->val<<" ";

            if(temp->next == nullptr)
            {
                break;
            }
            temp = temp->next;
        }

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
    int n, i=0;
    Singly_linked_list a;
    node* head = NULL;
    while(cin>>n)
    {
        a.pushback(n);
        /*if(i==0)
        {
            head->val=n;
        }*/
        i++;
    }
    // i=i/2;
    a.printfromMiddle(i);
    //a.display();
    //a.Print();

    return 0;
}

