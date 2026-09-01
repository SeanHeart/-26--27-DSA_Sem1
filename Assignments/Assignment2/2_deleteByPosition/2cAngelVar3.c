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


AngelV3V4 deleteV3(AngelV3V4 B, int pos){
    if(pos <=0 || pos > B.lastNdx+1){
        printf("Error: Invalid position!");
    }else{
        int truePos = pos-1;
        for(int i=truePos; i<B.lastNdx; i++){
            B.angels[i] = B.angels[i+1];
        }
        B.lastNdx--;
    }
    return B;
}

//suwat nya niiii yannnn