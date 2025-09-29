#include "stdio.h"
#include "stdlib.h"

// Define the node structure for the linked list
typedef struct Node
{
    int value;            // Value stored in this node
    struct Node *next;    // Pointer to the next node
} node_t;

// Define the list structure
typedef struct List
{
    node_t *head;   // Pointer to the first node (head of the list)
    int size;       // Number of nodes in the list
} list_t;

// Function declarations
void AddNode();                   // Add a new node to the list
void PrintList();                 // Print the entire list
node_t* CreateNode(int value);    // Create a new node and return a pointer to it

// Declare the list as a global variable, initialized as empty
list_t list = {NULL, 0};  

int main()
{
    int choice = 0 ;
	while(choice != 2)  // Program keeps running until user chooses 2
	{
		// Menu for the user
		printf("To add node enter 0\n");
		printf("To print the linked list enter 1\n");
		printf("To exit enter 2\n");			
		printf("Your choice : ");
		scanf("%d", &choice);
	
		// Switch based on user choice
		switch(choice)
		{
			case 0 :  
                AddNode();	   								 
                break ;
			case 1 :
                PrintList();      								 
                break ;
			case 2 : // Exit the program
                break ;
			default :
                printf("Invalid Choice, Pleas try again \n");   
                break ;			
		}
	}
	printf("Thank you \nGood Bye");
	return 0 ;
}

// Function to create a new node and return a pointer to it
node_t* CreateNode(int value)
{
    node_t *newNode = (node_t*)malloc(sizeof(node_t)); // Allocate memory for the node
    newNode->value = value;   // Store the given value in the node
    newNode->next = NULL;     // Initially, the node does not point to another node
    return newNode;           // Return pointer to the new node
}

// Function to add a node at the end of the list
void AddNode()
{
    int value;
    printf("Please add the node value: ");
    scanf("%d", &value);

    node_t *newNode = CreateNode(value); // Create a new node with the given value

    if (list.head == NULL) // If the list is empty
    {
        list.head = newNode;   // The new node becomes the head
    }
    else
    {
        // Traverse the list until the last node
        node_t *temp = list.head;
        while (temp->next != NULL)  
            temp = temp->next;
        temp->next = newNode;  // Link the last node to the new node
    }
    list.size++; // Increase the size of the list
}

// Function to print the linked list
void PrintList()
{
    node_t *temp = list.head;
    if(temp == NULL) // If the list is empty
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    // Print values one by one
    while(temp != NULL)
    {
        printf("%d, ", temp->value); // Print node value
        temp = temp->next;             // Move to the next node
    }
    printf("NULL\n"); // End of the list
}
