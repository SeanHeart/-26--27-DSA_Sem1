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


AngelV1V2 delete(AngelV1V2 A, int pos){
    if(pos <=0 || pos > A.lastNdx+1){
        printf("Error: Invalid position!");
    }else{
        int truePos = pos-1;
        for(int i=truePos; i<A.lastNdx; i++){
            A.angels[i] = A.angels[i+1];
        }
        A.lastNdx--;
    }
    return A;
}
