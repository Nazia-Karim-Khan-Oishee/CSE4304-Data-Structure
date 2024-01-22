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





// Given a reference (pointer to pointer) to the head
// of a list and an int, appends a new node at the end
void pushback(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	// Used in step 5
	Node *last = *head_ref;

	// 2. Put in the data
	new_node->data = new_data;

	// 3. This new node is going to be
	// the last node, so make next of
	// it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty,
	// then make the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL)
	{
		last = last->next;
	}

	// 6. Change the next of last node
	last->next = new_node;
	return;
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
pushback(&head, 4);
//insertAfter(head, 0);
    //push(*head , 0);
    Print(head);
    return 0;
}

