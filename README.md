# Doubly Linked List

A doubly linked list is a type of linked list in which each node consists of 3 components:
- *prev -> address of the previous node
- data -> data item
- *next -> address of next node

Here is the code of how to represent a doubly linked list in C++
```
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}
```
Those codes can also be written in a form like this to shorten the code
```
struct node 
{
    int data;
    Node *next, *prev;
}
```
Each struct node has a data item, a pointer to the previous struct node, and a pointer to the next struct node.

In its rough form, doubly linked list is written as below
```
/* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data = 3;

/* Connect nodes */
one->next = two;
one->prev = NULL;

two->next = three;
two->prev = one;

three->next = NULL;
three->prev = two;

/* Save address of first node in head */
head = one;
```
In the above code, one, two, and three are the nodes with data items 1, 2, and 3 respectively.
- For node one: next stores the address of two and prev stores null (there is no node before it).
- For node two: next stores the address of three and prev stores the address of one.
- For node three: next stores null (there is no node after it) and prev stores the address of two.
<br>

Reference:<br>
[Doubly Linked List by Programiz](https://www.programiz.com/dsa/doubly-linked-list)
