//1a
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


AngelV1V2 insert(AngelV1V2 A, int pos, Angel toInsert){
    //validation
    if(pos <= 1 || pos > A.lastNdx = 20-1){
        printf("Error: Invalid position!");
    }

    int truePos = pos-1;
    //shifting
    for(int i=A.lastNdx; i > truePos; i--){
        A.angels[i] = A.angels[i+1];
    }

    //adding
    A.angels[truePos] = toInsert;
    A.lastNdx++;

    return A;
}

//tarongon pa ko nii [Sept 1, 2026]