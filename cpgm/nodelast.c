// Simple C program to find n'th node from end
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
int data;
struct node* next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct node* head, int n)
{
	int len = 0, i;
	struct node *temp = head;

	// 1) count the number of nodes in Linked List
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	// check if value of n is not more than length of the linked list
	if (len < n)
	return;

	temp = head;

	// 2) get the (n-len+1)th node from the begining
	for (i = 1; i < len-n+1; i++)
	temp = temp->next;

	printf ("%d", temp->data);

	return;
}

void push(struct node** head_ref, int new_data)
{
/* allocate node */
struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

/* put in the data */
new_node->data = new_data;

/* link the old list off the new node */
new_node->next = (*head_ref);

/* move the head to point to the new node */
(*head_ref) = new_node;
}

/* Drier program to test above function*/
int main()
{
/* Start with the empty list */
struct node* head = NULL;

// create linked 35->15->4->20
push(&head, 20);
push(&head, 4);
push(&head, 15);
push(&head, 35);

printNthFromLast(head, 5);
return 0; 
}
