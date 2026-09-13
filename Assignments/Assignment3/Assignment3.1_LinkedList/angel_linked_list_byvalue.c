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

// Node stores the Angel directly (by value) -- each node owns a full copy
typedef struct Node {
    Angel data;
    struct Node* next;
} Node;

// Creates a new node, copying the given Angel into it
Node* createNode(Angel a) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = a; // struct copy
    newNode->next = NULL;
    return newNode;
}

// Inserts a new Angel node at the given position (0-indexed)
void insertByPosition(Node** head, Angel a, int position) {
    Node* newNode = createNode(a);

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
void deleteByPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;

    if (position <= 0) {
        *head = temp->next;
        free(temp);
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
               index, temp->data.name, temp->data.designation,
               temp->data.ability, temp->data.dmg, temp->data.color);
        temp = temp->next;
        index++;
    }
}

// Frees every node (and its embedded Angel data, freed automatically with it)
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
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

    printf("=== List (Angel stored by value) ===\n");
    displayList(head);

    printf("\nDeleting position 1\n");
    deleteByPosition(&head, 1);
    displayList(head);

    freeList(head);
    return 0;
}
