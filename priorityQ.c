#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to initialize the priority queue
void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to insert an element into the priority queue
void insert(PriorityQueue *pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }

    int i = pq->size;
    while (i > 0 && value > pq->data[(i - 1) / 2]) {
        pq->data[i] = pq->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->data[i] = value;
    pq->size++;
}

// Function to remove and return the element with the highest priority
int extractMax(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int max = pq->data[0];
    int last = pq->data[pq->size - 1];
    pq->size--;

    int i = 0, child;
    while (2 * i + 1 < pq->size) {
        child = 2 * i + 1;
        if (child + 1 < pq->size && pq->data[child + 1] > pq->data[child]) {
            child++;
        }
        if (last >= pq->data[child]) {
            break;
        }
        pq->data[i] = pq->data[child];
        i = child;
    }
    pq->data[i] = last;

    return max;
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    insert(&pq, 5);
    insert(&pq, 10);
    insert(&pq, 3);
    insert(&pq, 7);

    printf("Extracted max: %d\n", extractMax(&pq));
    printf("Extracted max: %d\n", extractMax(&pq));

    return 0;
}
