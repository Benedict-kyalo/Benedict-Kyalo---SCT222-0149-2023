#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        exit(1);            // Exit if memory allocation failed
    }
    newNode->data = data;   // Initialize the data
    newNode->next = NULL;   // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the end of the list
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Insert the new node at the end
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) { // Traverse the list
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Function to merge two sorted linked lists into one sorted linked list
struct Node* merge(struct Node* list1, struct Node* list2) {
    // Print the original lists
    printf("\nFirst Sorted List: ");
    printList(list1);
    printf("Second Sorted List: ");
    printList(list2);
    
    // Handle cases where one of the lists is empty
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct Node* mergedList = NULL; // Pointer to the head of the merged list
    struct Node* current = NULL;    // Pointer to track the current position in the merged list
    
    // Initialize the head of the merged list
    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }
    
    current = mergedList; // Set the current pointer to the head of the merged list
    
    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next; // Move the current pointer
    }
    
    // Add remaining elements from list1, if any
    if (list1 != NULL) {
        current->next = list1;
    }
    // Add remaining elements from list2, if any
    if (list2 != NULL) {
        current->next = list2;
    }
    
    // Print the merged list
    printf("Merged Sorted List: ");
    printList(mergedList);
    
    return mergedList; // Return the head of the merged list
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    // Create the first sorted list: 1 -> 3 -> 5 -> 7
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);
    insertEnd(&list1, 7);
    
    // Create the second sorted list: 2 -> 4 -> 6 -> 8
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);
    insertEnd(&list2, 8);
    
    // Merge the two sorted lists
    struct Node* mergedList = merge(list1, list2);
    
    return 0;
}