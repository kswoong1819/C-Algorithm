#include <stdio.h>
#include <malloc.h>

#define MaxSz 50001

typedef struct {
	int e, w;
	struct node* nxt;
}node;

node* arr[MaxSz];
int visited[MaxSz] = { 0, };
int meter = 1, new_start = 0, mincost = 0;

void dfs(int k, int len, int cost) {
	if (meter < len) {
		new_start = k;
		meter = len;
		mincost = cost;
	}
	else if (meter == len && mincost > cost) {
		new_start = k;
		mincost = cost;
	}

	visited[k] = 1;
	node* tmp = arr[k];
	while (tmp) {
		if (visited[tmp->e]) {
			tmp = tmp->nxt;
			continue;
		}
		dfs(tmp->e, len + 1, cost + tmp->w);
		tmp = tmp->nxt;
	}
	return;
}

int main() {
	int n, t, a, b, c;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tmp = (node*)malloc(sizeof(node));
		tmp->e = a;
		tmp->w = c;
		tmp->nxt = arr[b];
		arr[b] = tmp;

		tmp = (node*)malloc(sizeof(node));
		tmp->e = b;
		tmp->w = c;
		tmp->nxt = arr[a];
		arr[a] = tmp;
	}

	dfs(1, 1, 0);
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}
	meter = 1;
	mincost = 0;
	dfs(new_start, 1, 0);
	int result = mincost / t;
	if (mincost % t)
		result++;
	printf("%d\n", result);
	return 0;
}