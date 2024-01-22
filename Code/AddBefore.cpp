/*#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void Print(Node *head)
{
    Node *a =head;
    while(a!=NULL)
	{

        cout<<a->data<<endl;
        a = a->next;
    }
}
void insertBefore(Node* head, Node* given_ptr, int new_data)
{

	Node *a = new Node();
    for(a=head; ; a=a->next) 
    {
        if(a->next==given_ptr)
        {
Node *b = new Node();
Node *temp ;
b->data = new_data;
//temp = a->next;
a->next = b;
b->next = given_ptr;
break;

        }
    }
}
int main (){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

insertBefore(head, head, 0);
insertBefore(head,second, 8);
     
    //push(*head , 0);
    Print(head);
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void Print(Node *head)
{
    Node *a = head;
    while (a != NULL)
    {

        cout << a->data << endl;
        a = a->next;
    }
}
void insertBefore(Node *head, Node *given_ptr, int new_data)
{

    Node *a = new Node();
    for (a = head;; a = a->next)
    {
        if (a->next == given_ptr)
        {
            Node *b = new Node();
            Node *temp;
            b->data = new_data;
            // temp = a->next;
            a->next = b;
            b->next = given_ptr;
            break;
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    
    insertBefore(head, second, 8);

    // push(*head , 0);
    Print(head);
    return 0;
}
