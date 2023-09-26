#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the deque
struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

// Initialize a deque
void initializeDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Check if the deque is full
int isFull(struct Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

// Add an element to the front of the deque
void addToFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot add to the front.\n");
        return;
    }
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }
    
    deque->arr[deque->front] = data;
}

// Add an element to the rear of the deque
void addToRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot add to the rear.\n");
        return;
    }
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    
    deque->arr[deque->rear] = data;
}

// Remove an element from the front of the deque
int removeFromFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the front.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    
    int data = deque->arr[deque->front];
    
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    
    return data;
}

// Remove an element from the rear of the deque
int removeFromRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the rear.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    
    int data = deque->arr[deque->rear];
    
    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }
    
    return data;
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);
    
    addToFront(&deque, 1);
    addToRear(&deque, 2);
    addToFront(&deque, 3);
    addToRear(&deque, 4);
    
    printf("Front element: %d\n", removeFromFront(&deque));
    printf("Rear element: %d\n", removeFromRear(&deque));
    
    return 0;
}
