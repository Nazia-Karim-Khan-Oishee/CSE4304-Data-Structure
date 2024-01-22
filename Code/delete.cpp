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




void deleteN(Node** head, int position)
{
	Node* temp;
	Node* prev;
	temp = *head;
	prev = *head;
	for (int i = 0; i < position; i++) {
		if (i == 0 && position == 1) {
			*head = (*head)->next;
			free(temp);
		}
		else {
			if (i == position - 1 && temp) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
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

deleteN(&head, 3);
//insertBefore(head,third, 8);
     
    //push(*head , 0);
    Print(head);
    return 0;
}

