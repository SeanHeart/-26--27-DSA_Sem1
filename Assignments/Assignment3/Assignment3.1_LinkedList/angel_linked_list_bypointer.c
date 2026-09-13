#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define String char[50]

typedef struct{
    String name; //sachiel
    int designation; //3,4,5
    String ability;
    int dmg;
    String color;
} Angel;

// Node stores a POINTER to an Angel -- the Angel itself lives on the heap separately
typedef struct Node {
    Angel* data;
    struct Node* next;
} Node;

// Allocates a new Angel on the heap and copies the given values into it
Angel* createAngel(Angel a) {
    Angel* newAngel = (Angel*)malloc(sizeof(Angel));
    if (newAngel == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    *newAngel = a; // struct copy into the heap-allocated Angel
    return newAngel;
}

// Creates a new node pointing to the given Angel
Node* createNode(Angel* a) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = a; // just stores the address
    newNode->next = NULL;
    return newNode;
}

// Inserts a new Angel node at the given position (0-indexed)
void insertByPosition(Node** head, Angel a, int position) {
    Angel* newAngel = createAngel(a);
    Node* newNode = createNode(newAngel);

    if (*head == NULL || position <= 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;
    while (index < position - 1 && temp->next != NULL) {
        temp = temp->next;
        index++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletes the node at the given position (0-indexed)
// Must free BOTH the Angel it points to AND the node itself
void deleteByPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;

    if (position <= 0) {
        *head = temp->next;
        free(temp->data); // free the Angel first
        free(temp);        // then the node
        return;
    }

    Node* prev = NULL;
    int index = 0;
    while (temp != NULL && index < position) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp->data);
    free(temp);
}

// Prints all Angels currently in the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        printf("[%d] Name: %-10s Designation: %d  Ability: %-18s Dmg: %-4d Color: %s\n",
               index, temp->data->name, temp->data->designation,
               temp->data->ability, temp->data->dmg, temp->data->color);
        temp = temp->next;
        index++;
    }
}

// Frees every node AND every Angel it points to
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data); // free the Angel
        free(temp);        // free the node
    }
}

int main() {
    Node* head = NULL;

    Angel a1 = {"Sachiel", 3, "Hydraulic Pressure", 500, "Blue"};
    Angel a2 = {"Shamshel", 4, "Whip Sinews", 450, "Orange"};
    Angel a3 = {"Ramiel", 5, "Beam Cannon", 900, "Violet"};

    insertByPosition(&head, a1, 0);
    insertByPosition(&head, a2, 1);
    insertByPosition(&head, a3, 1);

    printf("=== List (Angel stored by pointer) ===\n");
    displayList(head);

    printf("\nDeleting position 1\n");
    deleteByPosition(&head, 1);
    displayList(head);

    freeList(head);
    return 0;
}
