#include <stdio.h>
#include <string.h>
#define MAX 30

typedef char String[50];

typedef struct{
	String bookName;
	String authorName;
	String publishingHouse;
	int publishingYear;
	int totalPageNum;
}Book;

typedef struct{
	Book books[20];
	int bookCount;
}Shelf;

typedef struct{
	Shelf shelves[3];
	int totalBookCount;
}BookShelf;

BookShelf BS;
BookShelf *BointR;

void deleteByPublishingHouse(BookShelf *Bointer, String w) {
    for (int s = 0; s < 3; s++) {
        int count = 0;
        for (int trav = 0; trav < Bointer->shelves[s].bookCount; trav++) {
            if (strcmp(Bointer->shelves[s].books[trav].publishingHouse, w) != 0) {
                Bointer->shelves[s].books[count++] = Bointer->shelves[s].books[trav];
            } else {
                Bointer->totalBookCount--;
            }
        }
        Bointer->shelves[s].bookCount = count;
    }
}

void printTopShelf(){
    printf("Top shelf (bookCount = %d):\n", BS.shelves[0].bookCount);
    for(int i=0; i<BS.shelves[0].bookCount; i++){
        printf(" [%d] publishingHouse = %s\n", i, BS.shelves[0].books[i].publishingHouse);
    }
}


int main(){
    BookShelf *Bointer = &BS;

    //populate the top shelf with 4 books
    strcpy(BS.shelves[0].books[0].publishingHouse, "Penguin");
    strcpy(BS.shelves[0].books[1].publishingHouse, "Harper");
    strcpy(BS.shelves[0].books[2].publishingHouse, "Penguin");
    strcpy(BS.shelves[0].books[3].publishingHouse, "March");
    BS.shelves[0].bookCount = 4;

    printf("BEFORE:\n");
    printTopShelf();
    
    deleteByPublishingHouse(Bointer, "Penguin");

    printf("\nAFTER Deleting \"Penguin\":\n");
    printTopShelf();

	return 0;
}

//it works but idk if its correct
//from GeminiAI
//i used this pang answer