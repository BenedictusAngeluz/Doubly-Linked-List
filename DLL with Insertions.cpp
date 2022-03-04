#include <iostream>

struct Node 
{
  	int data;
  	Node *next, *prev;
};

void insert_beginning(Node** head, int data) 
{
  	Node* newNode = new Node;
  	
  	newNode->data = data;
  	newNode->next = (*head);
  	newNode->prev = NULL;
  	
  	if((*head) != NULL)
    		(*head)->prev = newNode;

  	(*head) = newNode;
}

void insert_indexN(Node* prev_node, int data) 
{
  	if(prev_node == NULL) 
	{
    		std::cout << "previous node cannot be null";
    		return;
  	}

  	Node* newNode = new Node;

  	newNode->data = data;
  	newNode->next = prev_node->next;
  	prev_node->next = newNode;
  	newNode->prev = prev_node;

  	if(newNode->next != NULL)
    		newNode->next->prev = newNode;
}

void insert_end(Node** head, int data) 
{
  	Node* newNode = new Node;

  	newNode->data = data;
  	newNode->next = NULL;

  	Node* temp = *head;

  	if(*head == NULL)
	{
    		newNode->prev = NULL;
    		*head = newNode;
    		return;
  	}

  	while(temp->next != NULL)
    		temp = temp->next;
    
  	temp->next = newNode;
  	newNode->prev = temp;
}

void printLinkedList(Node* node) 
{
  	std::cout << "NULL <== ";

   	while(node != NULL)
	{
		std::cout << "node: " << node->data;
      		node = node->next;
      	
		if(node == NULL)
      		std::cout << " ==> NULL";
      		else
      		std::cout << " <==> ";
   	}
}

int main() 
{
  	Node* head = NULL;

  	insert_end(&head, 3);
  	insert_beginning(&head, 2);
  	insert_beginning(&head, 1);
  	insert_end(&head, 4);

  	std::cout << "Doubly linked list before insertion: " << std::endl;
  	printLinkedList(head);
	
	insert_indexN(head, 11);
	std::cout << "\n\nDoubly linked list after insertion at index 2 (after head/beginning): " << std::endl;
	printLinkedList(head);
	
	insert_indexN(head->next, 21);
	std::cout << "\n\nDoubly linked list after insertion at index 3 (after second node) : " << std::endl;
	printLinkedList(head);
	
	insert_indexN(head->next->next->next->next->next, 5);
	std::cout << "\n\nDoubly linked list after insertion at index 7 (at the end of the node) : " << std::endl;
	printLinkedList(head);
}
