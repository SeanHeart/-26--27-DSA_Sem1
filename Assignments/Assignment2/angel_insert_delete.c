#include <stdio.h>

#define MAX 30
typedef char String[50];

typedef struct{
    String name;        //sachiel
    int designation;     //3,4,5
    String ability;
    int dmg;
    String color;
}Angel;

typedef struct{
    Angel angels[20];
    int lastNdx;
}AngelV1V2;

typedef struct{
    Angel *angels;
    int lastNdx;
}AngelV3V4;

/* ============================================================
   1. insertByPosition
   ============================================================ */

// 1a - AngelV1V2, pass by VALUE -> must return AngelV1V2
AngelV1V2 insertV1(AngelV1V2 A, int pos, Angel toInsert){
    if(pos < 1 || pos > A.lastNdx + 2 || A.lastNdx >= 19){
        printf("Error: Invalid position | Full\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = A.lastNdx; ndx >= truePos; ndx--){
            A.angels[ndx+1] = A.angels[ndx];
        }
        A.angels[truePos] = toInsert;
        A.lastNdx++;
    }
    return A;
}

// 1b - AngelV1V2, pass by POINTER -> void
void insertV1Ptr(AngelV1V2 *Aptr, int pos, Angel toInsert){
    if(pos < 1 || pos > Aptr->lastNdx + 2 || Aptr->lastNdx >= 19){
        printf("Error: Invalid position | Full\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = Aptr->lastNdx; ndx >= truePos; ndx--){
            Aptr->angels[ndx+1] = Aptr->angels[ndx];
        }
        Aptr->angels[truePos] = toInsert;
        Aptr->lastNdx++;
    }
}

// 1c - AngelV3V4, pass by VALUE -> must return AngelV3V4
AngelV3V4 insertV3(AngelV3V4 B, int pos, Angel toInsert){
    if(pos < 1 || pos > B.lastNdx + 2 || B.lastNdx >= MAX - 1){
        printf("Error: Invalid position | Full\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = B.lastNdx; ndx >= truePos; ndx--){
            B.angels[ndx+1] = B.angels[ndx];
        }
        B.angels[truePos] = toInsert;
        B.lastNdx++;
    }
    return B;
}

// 1d - AngelV3V4, pass by POINTER -> void
void insertV3Ptr(AngelV3V4 *Bptr, int pos, Angel toInsert){
    if(pos < 1 || pos > Bptr->lastNdx + 2 || Bptr->lastNdx >= MAX - 1){
        printf("Error: Invalid position | Full\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = Bptr->lastNdx; ndx >= truePos; ndx--){
            Bptr->angels[ndx+1] = Bptr->angels[ndx];
        }
        Bptr->angels[truePos] = toInsert;
        Bptr->lastNdx++;
    }
}

/* ============================================================
   2. deleteByPosition
   ============================================================ */

// 2a - AngelV1V2, pass by VALUE -> must return AngelV1V2
AngelV1V2 deleteV1(AngelV1V2 A, int pos){
    if(pos < 1 || pos > A.lastNdx + 1){
        printf("Error: Invalid position\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = truePos; ndx < A.lastNdx; ndx++){
            A.angels[ndx] = A.angels[ndx+1];
        }
        A.lastNdx--;
    }
    return A;
}

// 2b - AngelV1V2, pass by POINTER -> void
void deleteV1Ptr(AngelV1V2 *Aptr, int pos){
    if(pos < 1 || pos > Aptr->lastNdx + 1){
        printf("Error: Invalid position\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = truePos; ndx < Aptr->lastNdx; ndx++){
            Aptr->angels[ndx] = Aptr->angels[ndx+1];
        }
        Aptr->lastNdx--;
    }
}

// 2c - AngelV3V4, pass by VALUE -> must return AngelV3V4
AngelV3V4 deleteV3(AngelV3V4 B, int pos){
    if(pos < 1 || pos > B.lastNdx + 1){
        printf("Error: Invalid position\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = truePos; ndx < B.lastNdx; ndx++){
            B.angels[ndx] = B.angels[ndx+1];
        }
        B.lastNdx--;
    }
    return B;
}

// 2d - AngelV3V4, pass by POINTER -> void
void deleteV3Ptr(AngelV3V4 *Bptr, int pos){
    if(pos < 1 || pos > Bptr->lastNdx + 1){
        printf("Error: Invalid position\n");
    } else {
        int truePos = pos - 1;
        for(int ndx = truePos; ndx < Bptr->lastNdx; ndx++){
            Bptr->angels[ndx] = Bptr->angels[ndx+1];
        }
        Bptr->lastNdx--;
    }
}

/* ============================================================
   NOTE: C does not support function overloading, so each of
   the 8 versions above needs a unique name (V1, V1Ptr, V3,
   V3Ptr) even though the assignment lists them all as
   "insert" / "delete". Rename them to match your assignment's
   required naming convention if one is specified.
   ============================================================ */
