#include <iostream>
#include <cstdlib>

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

void delete_indexN(Node** head, Node* del_node) 
{
  	if (*head == NULL || del_node == NULL)
    	return;

  	if (*head == del_node)
    	*head = del_node->next;

  	if (del_node->next != NULL)
    	del_node->next->prev = del_node->prev;

  	if (del_node->prev != NULL)
    	del_node->prev->next = del_node->next;

  	free(del_node);
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

  	std::cout << "Doubly linked list before deletion: " << std::endl;
  	printLinkedList(head);
	
	delete_indexN(&head, head);
	std::cout << "\n\nDoubly linked list after deletion at index 1 (beginning): " << std::endl;
	printLinkedList(head);
	
	delete_indexN(&head, head->next->next);
	std::cout << "\n\nDoubly linked list after deletion at last index (at the end of the node) : " << std::endl;
	printLinkedList(head);
	
	delete_indexN(&head, head->next);
	std::cout << "\n\nDoubly linked list after deletion at index 2 (after first node) : " << std::endl;
	printLinkedList(head);
}
