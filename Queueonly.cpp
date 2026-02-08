#include <stdio.h>
#define queue 100

typedef struct {
	int A[queue];
	int front, rear;
}Queue;

void makenull_Q(Queue *Q) {
	Q->front = Q->rear = -1;
}

int empty_Q(Queue Q) {
	return Q.front == -1;
}

int full_Q(Queue Q) {
	return (Q.rear - Q.front + 1) == queue;
}

void dequeue_Q(Queue *Q) {
	Q->front++;
	if(Q->front > Q->rear) {
		makenull_Q(Q);
	}
}

void enqueue_Q(Queue *Q, int x) {
	if(empty_Q(*Q)) Q->front = 0;
	Q->rear++;
	Q->A[Q->rear] = x;
}

int front_Q(Queue Q) {
	return Q.A[Q.front];
}

int main() {
	Queue Q; 
	makenull_Q(&Q);
	printf("check empty: ");
	if(empty_Q(Q)) {
		printf("Yes");
	} else {
		printf("No");
	}
	printf("\n");
	for(int i = 1; i<= 100; i++) {
		enqueue_Q(&Q, i);
	}
	for(int i = 1; i <= 100; i++) {
		printf("%03d ", front_Q(Q));
		if(i % 10 == 0) {
			printf("\n");
		}
		dequeue_Q(&Q);
	}
	if(empty_Q(Q)) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
