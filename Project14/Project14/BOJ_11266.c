#include <stdio.h>
#include <malloc.h>

#define MaxSz 10001

typedef struct nd {
	int p;
	struct nd* nxt;
}node;

int check[MaxSz];
node* arr[MaxSz];

int main() {
	int v, e, a, b;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		check[a]++;
		check[b]++;

		tmp = malloc(sizeof(node));
		tmp->p = a;
		tmp->nxt = arr[b];
		arr[b] = tmp;

		tmp = malloc(sizeof(node));
		tmp->p = b;
		tmp->nxt = arr[a];
		arr[a] = tmp;
	}
	for (int i = 1; i <= v; i++) {
		int visited[MaxSz] = { 0, };
		go();
	}
}