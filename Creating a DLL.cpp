#include <iostream>

struct Node
{
   	int data;
   	Node *prev, *next;
};

void insert_node(Node** head, int data) 
{
   	Node* newNode = new Node;
   	
   	newNode->data = data;
   	newNode->prev = NULL;
   	newNode->next = (*head);
   	
	if((*head) != NULL) 
	{
      	(*head)->prev = newNode;
   	}
   	
   	(*head) = newNode;
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
   	
   	insert_node(&head, 5);
   	insert_node(&head, 4);
   	insert_node(&head, 3);
   	insert_node(&head, 2);
   	insert_node(&head, 1);
   	
   	std::cout << "Doubly Linked List:" << std::endl;
   	printLinkedList(head);
   	return 0;
}
