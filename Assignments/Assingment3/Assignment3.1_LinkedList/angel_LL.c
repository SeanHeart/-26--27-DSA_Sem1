#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[50];

// Struct representing the data
typedef struct {
    String name;
    int designation;
    String ability;
    int dmg;
    String color;
} Angel;

// Struct representing a linked list node
typedef struct node {
    Angel elem;
    struct node* next;
} Node, *List;

// Function Prototypes
void initList(List* head);
void insertByPosition(List* head, Angel data, int position);
void deleteByPosition(List* head, int position);
void displayList(List head);

int main() {
    List angelList;
    initList(&angelList);

    // Sample Data Creation
    Angel a1 = {"Sachiel", 3, "Energy Blast", 100, "Black"};
    Angel a2 = {"Shamshel", 4, "Energy Whips", 150, "Pink"};
    Angel a3 = {"Ramiel", 5, "Particle Beam", 300, "Blue"};

    // Insertions
    insertByPosition(&angelList, a1, 1); // Insert at pos 1
    insertByPosition(&angelList, a3, 2); // Insert at pos 2
    insertByPosition(&angelList, a2, 2); // Insert at pos 2 (middle)

    printf("--- Angel List After Insertions ---\n");
    displayList(angelList);

    // Deletion
    deleteByPosition(&angelList, 2); // Delete node at pos 2

    printf("\n--- Angel List After Deleting Position 2 ---\n");
    displayList(angelList);

    return 0;
}

// Initialize the list to NULL
void initList(List* head) {
    *head = NULL;
}

// Insert an element by 1-based position index
void insertByPosition(List* head, Angel data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->elem = data;
    newNode->next = NULL;

    // Insert at the head (Position 1)
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to the position prior to insertion target
    Node* current = *head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Delete an element by 1-based position index
void deleteByPosition(List* head, int position) {
    if (*head == NULL || position < 1) {
        printf("List is empty or invalid position!\n");
        return;
    }

    Node* temp = *head;

    // Delete head node
    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse to node right before the target
    Node* current = *head;
    int i;
    for (i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Print all elements in the linked list
void displayList(List head) {
    Node* current = head;
    int pos = 1;

    while (current != NULL) {
        printf("[%d] Name: %s | Designation: %d | Ability: %s | DMG: %d | Color: %s\n",
               pos,
               current->elem.name,
               current->elem.designation,
               current->elem.ability,
               current->elem.dmg,
               current->elem.color);
        current = current->next;
        pos++;
    }
}