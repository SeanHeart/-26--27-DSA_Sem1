//Example of Variation 1: Static Array, Accessed by Value
#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];     //fixed-size array, allocated on stack
    int count;        //tracks how many elements are currently stored in the list
}List;

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
   //error checking
    if(position > L.count || position < 0){
        printf("Insert failed: invalid position.\n");
        return L;
    }
    if(L.count == MAX){
        printf("Insert failed: list is full.\n");
        return L;
    }

    // Shift elements right starting from the end, down to 'position'
    for(int i=L.count; i>position; i--){
        L.elem[i] = L.elem[i-1];
    }

    // Insert the element in the specificied position
    L.elem[position] = data;
    L.count++;        // update count
    return L;         // return list
}

List deletePos(List L, int position){
    //error catching
    if(position < 0 || position >= L.count){
        printf("Delete failed: Invalid position.\n");
        return L;
    }
    if(L.count == 0){
        printf("Delete failed: List is empty.\n");
        return L;
    }

    // Shift elements left starting from 'position'
    for(int i=position; i<L.count; i++){
        L.elem[i] = L.elem[i+1];
    }

    // update
    L.count--;

    return L;
}

int locate(List L, int data){
    for(int i=0; i<L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    // error checking
    if(L.count == MAX){
        printf("Insert failed: List is full.\n");
        return L;
    }

    int position = 0;
    // Find correct position for 'data'
    while (position < L.count && L.elem[position] < data){
        position++;
    }

    // Shift elements right to make space
    for(int i = L.count; i>position; i--){
        L.elem[i] = L.elem[i-1];
    }

    // update
    L.elem[position] = data;
    L.count++;

    return L;
}

void display(List L){
    printf("[");
    for(int i=0; i<L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("]\n");
}

int main(){
    List L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    printf("After inserts: ");
    display(L);

    L = insertPos(L, 4, 2);
    printf("After insertPos(L, 4, 2): ");
    display(L);

    L = deletePos(L, 1);
    printf("After deletePos(L, 1): ");
    display(L);

    int pos = locate(L, 2);
    printf("locate(L, 2) = %d\n", pos);

    L = insertSorted(L, 3);
    printf("After insertSorted(L, 3) [array not actually sorted here, for demo]: ");
    display(L);

    printf("Final count: %d\n", L.count);

    return 0;
}