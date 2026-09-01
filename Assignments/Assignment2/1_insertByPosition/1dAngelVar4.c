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
    Angel *angels;
    int lastNdx;
}AngelV3V4;

AngelV3V4 B;

void insertV4(AngelV3V4 *Bptr, int pos, Angel toInsert){
    if(pos <= 0 || pos > Bptr->lastNdx+1 || Bptr->lastNdx >= MAX-1){
        printf("Error: Invalid Position! || Array is full!");
    }else{
        int truePos = pos-1;
        for(int i=Bptr->lastNdx; i>=truePos; i--){
            Bptr->angels[i+1] = Bptr->angels[i];
        }
        Bptr->angels[truePos] = toInsert;
        Bptr->lastNdx++;
    }

    return B;
}
