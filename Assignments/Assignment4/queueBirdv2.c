#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIRDS 10

typedef char* String;   // lets us write "String name;" like in the assignment

typedef struct {
    String name;
    String specie;
    String color;
    int bread;
    int age;
} Bird;

typedef struct {
    Bird breadBirds[MAX_BIRDS];
    int start;
    int end;
} Queue;
// NOTE: no "count" field here. Because of that, we can only ever use
// MAX_BIRDS - 1 slots at once. That's the trade-off: one slot is always
// left empty on purpose, so "start == end" unambiguously means "empty",
// never "full". If we filled all 10 slots, start and end would collide
// and we couldn't tell full apart from empty.

// Call this first to prepare an empty queue
void initQueue(Queue *q) {
    q->start = 0;
    q->end = 0;
}

bool isEmpty(Queue *q) {
    return q->start == q->end;
}

bool isFull(Queue *q) {
    // "full" here means one slot away from colliding with start
    return (q->end + 1) % MAX_BIRDS == q->start;
}

// 1) void enqueue;
void enqueue(Queue *q, Bird b) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %s.\n", b.name);
        return;
    }
    q->breadBirds[q->end] = b;
    q->end = (q->end + 1) % MAX_BIRDS;  // wrap around, circular queue
}

// 1) void dequeue;
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    q->start = (q->start + 1) % MAX_BIRDS;  // just move the pointer forward
}

// 1) Bird front;
Bird front(Queue *q) {
    // caller should check isEmpty(q) before calling this
    return q->breadBirds[q->start];
}

// 2) void enqueueUnique; (color) -> only enqueue if no bird with that color exists yet
void enqueueUnique(Queue *q, Bird b) {
    int i = q->start;
    while (i != q->end) {
        if (strcmp(q->breadBirds[i].color, b.color) == 0) {
            printf("A bird with color '%s' already exists. Not enqueued.\n", b.color);
            return;
        }
        i = (i + 1) % MAX_BIRDS;
    }
    enqueue(q, b);
}

// 3) int countQueue;
int countQueue(Queue *q) {
    // no stored count, so we derive it from start/end instead
    return (q->end - q->start + MAX_BIRDS) % MAX_BIRDS;
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

//without count at the typedef struct{} so we'll use MAX_BIRDS - 1