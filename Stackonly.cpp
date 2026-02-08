#include <stdio.h>
#define stack 100

typedef struct {
	int A[stack];
	int top;
}Stack; 

void makenull_S(Stack *S) {
	S->top = stack;
}

int empty_S(Stack S) {
	return S.top == stack;
} 

int full_S (Stack S) {
	return S.top == 0;
}

int top_S(Stack S) {
	return S.A[S.top];
}

void pop_S(Stack *S) {
	if (!empty_S(*S)) {
		S->top++;
	}
}

void push_S(Stack *S, int x) {
	if(!full_S(*S)) {
		S->top--;
		S->A[S->top] = x;
	} else {
		printf("the list is full");
	}
}


int main() {
	Stack S; 
	makenull_S(&S);
	printf("check empty: ");
	
	if(empty_S(S)) {
		printf("Yes");
	} else {
		printf("No");
	}
	
	printf("\n\n");
	
	printf("check push: \n");
	for(int i = 0; i <= 99; i++) {
		push_S(&S, i + 1);
		printf("%03d ", top_S(S));
		if((i + 1) % 10 == 0 && i != 0) {
			printf("\n");
		}
	}
	printf("\ncheck pop: \n");
	for(int i = 0; i <= 99; i++) {
		pop_S(&S);
	}
	printf("delated 100 elements: ");
	if(empty_S(S)) {
		printf("Yes");
	} else {
		printf("No");
	}
	
	return 0;
}
