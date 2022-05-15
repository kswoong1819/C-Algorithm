#include <stdio.h>
#include <malloc.h>

typedef struct nd {
	int e;
	struct nd* nxt;
}node;

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* answer = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		answer[i] = -1;
		scanf("%d", &arr[i]);
	}
	node *stack, *tmp;
	stack = (node*)malloc(sizeof(node));
	stack->e = 0;
	stack->nxt = NULL;
	for (int j = 0; j < n; j++) {
		while (stack->nxt != NULL && arr[stack->e] < arr[j]) {
			answer[stack->e] = arr[j];
			stack = stack->nxt;
		}
		tmp = (node*)malloc(sizeof(node));
		tmp->e = j;
		tmp->nxt = stack;
		stack = tmp;
		// free(tmp);
	}
	free(stack);
	for (int i = 0; i < n; i++) {
		printf("%d ", answer[i]);
	}
}
