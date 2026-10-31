#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
typedef char String[50];

typedef struct {
    String bookName;
    String authorName;
    String genre;
    String publishingHouse;
    int publishingYear;
    int totalPageNum;
} Book;

typedef struct node {
    Book elem;
    struct node *next;
} BookType, *BookNode;

typedef struct {
    BookNode books[10];
} BookShelf;

/* 1) Hash: the bucket index is the genre's position in the illustration */
int Hash(String genre) {
    String genres[10] = {"Design", "Manga", "Fantasy", "Romance", "Horror",
                         "Young Adult", "SciFi", "Non Fiction", "Thriller", "Comics"};
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(genre, genres[i]) == 0) {
            return i;
        }
    }
    return -1;   /* genre not in the table */
}

/* 2) insert: add toInsert at the LAST position of its chain */
void insert(BookShelf *D, Book toInsert) {
    int idx = Hash(toInsert.genre);
    if (idx == -1) {
        return;
    }

    BookNode newNode = (BookNode)malloc(sizeof(BookType));
    if (newNode == NULL) {
        return;
    }
    newNode->elem = toInsert;
    newNode->next = NULL;

    if (D->books[idx] == NULL) {
        D->books[idx] = newNode;            /* empty bucket */
    } else {
        BookNode trav = D->books[idx];
        while (trav->next != NULL) {        /* walk to the last node */
            trav = trav->next;
        }
        trav->next = newNode;               /* link at the end */
    }
}

/* shows every bucket and its chain */
void display(BookShelf D) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ->", i);
        BookNode trav = D.books[i];
        while (trav != NULL) {
            printf(" [%s]", trav->elem.bookName);
            trav = trav->next;
        }
        printf(" NULL\n");
    }
}

/* frees every node */
void freeShelf(BookShelf *D) {
    int i;
    for (i = 0; i < 10; i++) {
        BookNode trav = D->books[i];
        while (trav != NULL) {
            BookNode temp = trav;
            trav = trav->next;
            free(temp);
        }
        D->books[i] = NULL;
    }
}

/* 3) Simulation with 15 book titles */
int main() {
    BookShelf shelf;
    int i;
    for (i = 0; i < 10; i++) {
        shelf.books[i] = NULL;              /* every bucket starts empty */
    }

    Book list[15] = {
        {"Spiderman",                  "Stan Lee",           "Comics",      "Marvel",           1962,   32},
        {"Batman",                     "Bob Kane",           "Comics",      "DC Comics",        1939,   64},
        {"The Hobbit",                 "J.R.R. Tolkien",     "Fantasy",     "Allen & Unwin",    1937,  310},
        {"Dracula",                    "Bram Stoker",        "Horror",      "Constable",        1897,  418},
        {"Dune",                       "Frank Herbert",      "SciFi",       "Chilton Books",    1965,  412},
        {"Pride and Prejudice",        "Jane Austen",        "Romance",     "T. Egerton",       1813,  279},
        {"Gone Girl",                  "Gillian Flynn",      "Thriller",    "Crown",            2012,  415},
        {"Naruto",                     "Masashi Kishimoto",  "Manga",       "Shueisha",         1999,  192},
        {"Educated",                   "Tara Westover",      "Non Fiction", "Random House",     2018,  352},
        {"The Hunger Games",           "Suzanne Collins",    "Young Adult", "Scholastic",       2008,  374},
        {"Design of Everyday Things",  "Don Norman",         "Design",      "Basic Books",      1988,  368},
        {"Harry Potter",               "J.K. Rowling",       "Fantasy",     "Bloomsbury",       1997,  223},
        {"It",                         "Stephen King",       "Horror",      "Viking",           1986, 1138},
        {"One Piece",                  "Eiichiro Oda",       "Manga",       "Shueisha",         1997,  216},
        {"Superman",                   "Jerry Siegel",       "Comics",      "DC Comics",        1938,   64}
    };

    for (i = 0; i < 15; i++) {
        insert(&shelf, list[i]);
    }

    display(shelf);
    freeShelf(&shelf);
    return 0;
}