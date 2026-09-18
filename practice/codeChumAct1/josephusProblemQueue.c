#include <stdio.h>
#include "queue.h"

void rotate(CircularQueue *q) {
    int val = dequeue(q);
    enqueue(q,val);
}

int josephus(int n, int k) {
    CircularQueue q;
    init(&q);

    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }

    while (q.list.count > 1) {
        for (int i = 0; i < k - 1; i++) {
            rotate(&q);
        }
        int eliminated = dequeue(&q);
        printf("Eliminated: %d\n", eliminated);
    }

    return dequeue(&q);
}