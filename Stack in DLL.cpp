#include <iostream>
#include <cstdlib>

struct Node{
	int data;
	Node *next, *prev;
};

// All insertions and deletion in doubly linked list
void insert_beginning(Node** head, int data){
	Node* newNode = new Node;
	
	newNode->data = data;
	newNode->next = (*head);
	newNode->prev = NULL;
	
	if((*head) != NULL)
		(*head)->prev = newNode;
	
	(*head) = newNode;
}

void insert_indexN(Node* prev_node, int data){
	if(prev_node == NULL){
		std::cout << "Previous node cannot be null";
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

void insert_end(Node** head, int data){
	Node* newNode = new Node;
	
	newNode->data = data;
	newNode->next = NULL;
	
	Node* temp = *head;
	
	if(*head == NULL){
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	
	while(temp->next != NULL)
		temp = temp->next;
		
	temp->next = newNode;
	newNode->prev = temp;
}

void delete_indexN(Node** head, Node* del_node){
	if(*head == NULL || del_node == NULL)
		return;
	
	if(*head == del_node)
		*head = del_node->next;
		
	if(del_node->next != NULL)
		del_node->next->prev = del_node->prev;
		
	if(del_node->prev != NULL)
		del_node->prev->next = del_node->next;
		
	free(del_node);
}

// Stack insertion and deletion in doubly linked list
void push(Node** head, int data){
	Node* newNode = new Node;
	
	if(*head == NULL){
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
		*head = newNode;
	}else{
		newNode->data = data;
		newNode->next = *head;
		(*head)->prev = newNode;
		newNode->prev = NULL;
		*head = newNode;
	}
}

void pop(Node** head){
	Node* newNode = new Node;
	
	if(*head == NULL){
		std::cout << "Stack is empty" << std::endl;
		return;
	}else if((*head)->next == NULL && (*head)->prev == NULL){
		newNode = *head;
		*head = NULL;
		delete(*head);
	}else{
		newNode = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		delete(newNode);
	}
}

// Print doubly linked list
void printLinkedList(Node* node){
	std::cout << "NULL <== ";
	
	while(node != NULL){
		std::cout << "node: " << node->data;
		node = node->next;
		
		if(node == NULL)
			std::cout << " ==> NULL";
		else
			std::cout << " <==> ";
	}
}

// Main program
int main(){
	Node* head = NULL;
	
        // Filling and deleting doubly linked list with original command
	std::cout << "Filling and Deleting Doubly Linked List with Original Command\n";
	std::cout << "=============================================================\n";
	
	std::cout << "Doubly linked list condition before insertion or deletion: " << std::endl;
	insert_end(&head, 3);
	insert_beginning(&head, 2);
	insert_beginning(&head, 1);
	insert_end(&head, 4);
	printLinkedList(head);
	
	std::cout << "\n\nDoubly linked list condition after insertion at index 2 (after second node): " << std::endl;
	insert_indexN(head->next, 21);
	printLinkedList(head);
	
	std::cout << "\n\nDoubly linked list condition after deletion at index 2: " << std::endl;
	delete_indexN(&head, head->next->next);
	printLinkedList(head);
	
        // Filling and deleting doubly linked list with stack
	std::cout << "\n\n\nFilling and Deleting Doubly Linked List with Stack\n";
	std::cout << "==================================================\n";
	
	std::cout << "Doubly linked list condition after insertion: " << std::endl;
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	printLinkedList(head);
	
	std::cout << "\n\nDoubly linked list condition after deletion: " << std::endl;
	pop(&head);
	printLinkedList(head);
}
