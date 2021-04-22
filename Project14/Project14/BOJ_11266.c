#include <stdio.h>
#include <malloc.h>

#define MaxSz 10001

typedef struct nd {
	int p;
	struct nd* nxt;
}node;

int check[MaxSz];
node* arr[MaxSz];
int visited[MaxSz] = { 0, };
int result = 0;
int result_arr[MaxSz];
int flag = 0;

void go(int init, int n, int k) {
	node* tmp = arr[n];
	while (tmp != NULL) {
		if (k >= 2 && tmp->p == init) {
			check[init]--;
			return;
		}
		if (visited[tmp->p]) {
			tmp = tmp->nxt;
			continue;
		}
		visited[tmp->p] = 1;
		go(init, tmp->p, k+1);
		visited[tmp->p] = 0;
		tmp = tmp->nxt;
	}
	return;
}

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
		if (check[i] >= 2) {
			visited[i] = 1;
			go(i, i, 0);
			visited[i] = 0;
			if (check[i] > 0)
				result_arr[result++] = i;
		}
	}
	printf("%d\n", result);
	for (int i = 0; i < result; i++) {
		printf("%d ", result_arr[i]);
	}
	return 0;
}