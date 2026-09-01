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

AngelV3V4 insert(AngelV3V4 B, int pos, Angel toInsert){
    if(pos <= 0 || pos > B.lastNdx+1 || B.lastNdx >= MAX-1){
        printf("Error: Invalid Position! || Array is full!");
    }else{
        int truePos = pos-1;
        for(int i=B.lastNdx; i>=truePos; i--){
            B.angels[i+1] = B.angels[i];
        }
        B.angels[truePos] = toInsert;
        B.lastNdx++;
    }

    return B;
}
