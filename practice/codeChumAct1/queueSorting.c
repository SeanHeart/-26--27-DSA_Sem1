#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    int queue[size];

    printf("Enter %d integers to add to the queue: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }

    // Sort ascending (simple bubble sort)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (queue[j] > queue[j + 1]) {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    printf("Sorted queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d", queue[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}