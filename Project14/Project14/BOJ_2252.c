#include <stdio.h>
#include <malloc.h>

#define MaxSz 32001

typedef struct nd {
	int e;
	struct nd* nxt;
}node;

int visited[MaxSz] = { 0, };
node* arr[MaxSz];

void go(int n) {
	int queue[MaxSz];
	int front = 0, rear = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0)
			queue[rear++] = i;
	}
	while (front < rear) {
		int q = queue[front++];
		printf("%d ", q);
		node* use, * tmp;
		use = arr[q];
		while (use != NULL) {
			tmp = use;
			visited[tmp->e]--;
			if (visited[tmp->e] == 0)
				queue[rear++] = tmp->e;
			use = use->nxt;
		}
	}
	return;
}

int main() {
	int n, m, a, b;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		tmp = malloc(sizeof(node));
		tmp->e = b;
		tmp->nxt = arr[a];
		arr[a] = tmp;

		visited[b]++;
	}
	go(n);
	return 0;
}