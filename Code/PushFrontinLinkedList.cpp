#include <bits/stdc++.h>

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
void push(Node** head_ref, int new_data)
{
   
    // 1. allocate node
    Node* new_node = new Node();
 
    // 2. put in the data
    new_node->data = new_data;
 
    // 3. Make next of new node as head
    new_node->next = (*head_ref);
 
    // 4. Move the head to point to
    // the new node
    (*head_ref) = new_node;
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

    push(&head , 0);
    Print(head);
    return 0;
}