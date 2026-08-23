#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
typedef char String[50];

typedef struct{
    String bookName;
    String authorName;
    String publishingHouse;
    int publishingYear;
    int totalPageNum;
}Books;

typedef struct node{
    Books book;
    struct node* link;
}Shelf;

typedef struct{
    Shelf *BookNook;
    int totalBookCount;
}BookShelf;


void insertBookNook(BookShelf *BSN, Books B[5]) {
    for (int i = 0; i < 5; i++) {
        // Step 1: Allocate memory for new node in the Heap
        Shelf *newNode = (Shelf *)malloc(sizeof(Shelf));
        if (newNode != NULL) {
            newNode->book = B[i];
            newNode->link = NULL;

            // Step 2: Use double pointer trav to traverse to the end of the list
            Shelf **trav = &(BSN->BookNook);
            while (*trav != NULL) {
                trav = &((*trav)->link);
            }

            // Step 3: Insert new node at the end
            *trav = newNode;
            BSN->totalBookCount++;
        }
    }
}

void printList(BookShelf *BSN){
    Shelf *trav = BSN->BookNook;
    printf("List (totalBookCount = %d):\n", BSN->totalBookCount);
    while(trav != NULL){
        printf("  %s\n", trav->book.bookName);
        trav = trav->link;
    }
}

int main(){
    BookShelf BSN = { NULL, 0 };

    Books bookArray[5];
    strcpy(bookArray[0].bookName, "Emma");
    strcpy(bookArray[1].bookName, "Dune");
    strcpy(bookArray[2].bookName, "1984");
    strcpy(bookArray[3].bookName, "Fable");
    strcpy(bookArray[4].bookName, "Beloved");

    insertBookNook(&BSN, bookArray);

    printList(&BSN);

    return 0;
}

//it works but idk if its correct