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

void insertSorted(BookShelf *BSN, Books arr[], int size){
    int i;

    for(i = 0; i < size; i++){
        Shelf *newNode = (Shelf*)malloc(sizeof(Shelf));
        newNode->book = arr[i];
        newNode->link = NULL;

        if(BSN->BookNook == NULL || strcmp(arr[i].bookName, BSN->BookNook->book.bookName) < 0){
            newNode->link = BSN->BookNook;
            BSN->BookNook = newNode;
        } else {
            Shelf *trav = BSN->BookNook;
            while(trav->link != NULL && strcmp(arr[i].bookName, trav->link->book.bookName) > 0){
                trav = trav->link;
            }
            newNode->link = trav->link;
            trav->link = newNode;
        }
        BSN->totalBookCount++;
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

    insertSorted(&BSN, bookArray, 5);

    printList(&BSN);

    return 0;
}


//it works but idk if its correct
//this version, mo sort lng siya