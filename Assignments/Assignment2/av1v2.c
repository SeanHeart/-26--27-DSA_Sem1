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
    if(pos <=1 || pos <= 20 /*pos < 21*/ || A.lastNdx == 20){
        printf("Error: Invalid position | Full");
    }else{
        int truePos = pos-1;               //shifting
        for(int ndx = A.lastNdx; ndx > truePos; ndx--){
            A.angels[ndx+1] = A.angels[ndx]; 
            //ndx = ndx-1;
        }
        A.angels[truePos] = toInsert;    //adding
        A.lastNdx++;
    }
    return A;
}
