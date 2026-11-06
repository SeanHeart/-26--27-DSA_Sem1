/*Date: November 6, 2026
Status: Done
Instructions: Bit Vector Activity
    (Check Notion or CodeChum)

Notes/Comments/Feedback: 
-It works but this doesn't have the helper function.
*/

//write code here
#include <stdio.h>

void displayAvailableProducts(unsigned char products) {
    int i = 1 << (sizeof(products) * 8 - 1);
    int prod = sizeof(products) * 8 - 1;

    printf("Available products:");

    while(i > 0){
        if(products & i){
            printf(" prod_%d", prod);
        }
        i = i >> 1;
        prod--;
    }
    printf("\n");

}

void moveInventory(unsigned char *branchA, unsigned char *branchB) {
    unsigned char toMove = *branchA & ~(*branchB);

    *branchB |= toMove;
    *branchA &= ~toMove;

    printf("Products moved successfully.\n");
}

void unavailableProducts(unsigned char branchA, unsigned char branchB) {
    unsigned char unavailable = ~(branchA |= branchB);

    int i = 1 << (sizeof(unavailable) * 8 - 1);
    int prod = sizeof(unavailable) * 8 - 1;

    printf("Unavailable products:");

    while(i > 0){
        if(unavailable & i){
            printf(" prod_%d", prod);
        }
        i = i >> 1;
        prod--; 
    }
    printf("\n");

}

int main() {
    unsigned char branch_A = 0;
    unsigned char branch_B = 0;

    branch_A |= (1 << 7);
    branch_A |= (1 << 5);
    branch_A |= (1 << 4);
    branch_A |= (1 << 2);
    branch_A |= (1 << 0);

    displayAvailableProducts(branch_A);

    branch_A = 0;
    branch_B = 0;

    branch_A |= (1 << 7);
    branch_A |= (1 << 6);
    branch_A |= (1 << 4);
    branch_A |= (1 << 3);
    branch_A |= (1 << 0);

    branch_B |= (1 << 7);
    branch_B |= (1 << 6);
    branch_B |= (1 << 5);
    branch_B |= (1 << 2);
    branch_B |= (1 << 0);

    moveInventory(&branch_A, &branch_B);
    displayAvailableProducts(branch_A);
    displayAvailableProducts(branch_B);

    branch_A = 0;
    branch_B = 0;

    branch_A |= (1 << 5);
    branch_A |= (1 << 4);
    branch_A |= (1 << 1);

    branch_B |= (1 << 6);
    branch_B |= (1 << 3);
    branch_B |= (1 << 1);

    unavailableProducts(branch_A, branch_B);

    return 0;
}