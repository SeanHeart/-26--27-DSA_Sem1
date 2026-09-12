#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIRDS 10

typedef struct {
    char name[50];
    char specie[50];
    char color[50];
    int bread;
    int age;
} Bird;

typedef struct {
    Bird breadBirds[MAX_BIRDS];
    int start;
    int end;
    int count;   // tracks how many birds are currently in the queue
} Queue;

// Call this first to prepare an empty queue
void initQueue(Queue *q) {
    q->start = 0;
    q->end = 0;
    q->count = 0;
}

bool isFull(Queue *q) {
    return q->count == MAX_BIRDS;
}

bool isEmpty(Queue *q) {
    return q->count == 0;
}

// 1) void enqueue;
void enqueue(Queue *q, Bird b) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %s.\n", b.name);
        return;
    }
    q->breadBirds[q->end] = b;
    q->end = (q->end + 1) % MAX_BIRDS;  // wrap around, circular queue
    q->count++;
}

// 1) void dequeue;
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    q->start = (q->start + 1) % MAX_BIRDS;  // just move the pointer forward
    q->count--;
}

// 1) Bird front;
Bird front(Queue *q) {
    // caller should check isEmpty(q) before calling this
    return q->breadBirds[q->start];
}

// 2) void enqueueUnique; (color) -> only enqueue if no bird with that color exists yet
void enqueueUnique(Queue *q, Bird b) {
    int i, idx;
    for (i = 0; i < q->count; i++) {
        idx = (q->start + i) % MAX_BIRDS;
        if (strcmp(q->breadBirds[idx].color, b.color) == 0) {
            printf("A bird with color '%s' already exists. Not enqueued.\n", b.color);
            return;
        }
    }
    enqueue(q, b);
}

// 3) int countQueue;
int countQueue(Queue *q) {
    return q->count;
}

// --- simple test driver ---
int main(void) {
    Queue q;
    initQueue(&q);

    Bird b1 = {"Tweety", "Canary", "Yellow", 1, 2};
    Bird b2 = {"Zazu",   "Hornbill", "Red", 0, 5};
    Bird b3 = {"Iago",   "Macaw", "Yellow", 1, 3}; // duplicate color, should be rejected

    enqueue(&q, b1);
    enqueue(&q, b2);
    enqueueUnique(&q, b3);

    printf("Count: %d\n", countQueue(&q));
    printf("Front: %s\n", front(&q).name);

    dequeue(&q);
    printf("After dequeue, front: %s\n", front(&q).name);
    printf("Count: %d\n", countQueue(&q));

    return 0;
}

//from claudeAI