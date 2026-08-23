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


int main(){
    int checkTSBooksUnique(BookShelf BS);

    int result = checkTSBooksUnique(BS);

    printf("%d", result);
	
}

int checkTSBooksUnique(BookShelf BS){
    int count = BS.shelves[0].bookCount;
    
    for(int i = 0; i<count-1; i++){
        for(int j=i+1; j<count; j++){
            if(strcmp(BS.shelves[0].books[i].bookName, BS.shelves[0].books[j].bookName) == 0){
                return 0;
            }
        }
    }
    return 1;
}

//it runs but idk if its correct.