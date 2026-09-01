#include <stdio.h>
#include <stdlib.h>

#define MAX 30
typedef char String[50];

typedef struct{
    String name;
    int designation;
    String ability;
    int dmg;
    String color;
}Angel;

typedef struct{
    Angel angels[20];
    int lastNdx;
}AngelV1V2;

AngelV1V2 A;


void insert(AngelV1V2 *Aptr, int pos, Angel toInsert){
    if(pos <= 0 || pos > Aptr->lastNdx+1 || Aptr->lastNdx >= 20-1){
        printf("Error: Invalid Position! | Array is full!");
    }else{
        int truePos = pos-1;
        for(int i=Aptr->lastNdx; i>truePos; i--){
            Aptr->angels[i+1] = Aptr->angels[i];
        }

        Aptr->angels[truePos] = toInsert;
        Aptr->lastNdx++;
    }
}
