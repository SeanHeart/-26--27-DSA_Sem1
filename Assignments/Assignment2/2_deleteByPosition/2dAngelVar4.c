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


void delete(AngelV3V4 *Bptr, int pos){
    if(pos <=0 || pos > Bptr->lastNdx+1){
        printf("Error: Invalid position!");
    }else{
        int truePos = pos-1;
        for(int i=truePos; i<Bptr->lastNdx; i++){
            Bptr->angels[i] = Bptr->angels[i+1];
        }
        Bptr->lastNdx--;
    }
}