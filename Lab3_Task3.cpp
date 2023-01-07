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
    Singly_linked_list printfromMiddle()
    {
        node* slow = head;
        node* fast = head;/// 1 2 3
        while(1)
        {
//            slow = slow->next;///1 2
            //cout<<slow->val;
            if(fast->next!=nullptr)
            {
                fast = fast->next->next;//2 b
                slow = slow->next;///1 2
            }
            else
            {
                break;
            }
            if(fast==nullptr)
            {
                break;
            }

        }
        Singly_linked_list linky;
        while(slow!=nullptr)
        {
            linky.pushback(slow->val);
            slow=slow->next;
        }
        return linky;

    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << " ";
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
    int n, i=0;
    Singly_linked_list a,a_mid;
    node* head = NULL;
    while(cin>>n)
    {
        a.pushback(n);

        i++;
    }
    // i=i/2;
    a.display();
    a_mid=a.printfromMiddle();
    a_mid.display();
    //a.Print();

    return 0;
}


