#include <stdio.h>
#include <malloc.h>

#define MaxSz 100001

typedef struct nd {
	int e;
	struct nd* nxt;
}node;

node* arr[MaxSz];
int num[MaxSz], visited[MaxSz];

int dfs(int x) {
	node* tmp = arr[x];
	int val = 1;

	visited[x] = 1;
	while (tmp) {
		if (visited[tmp->e]) {
			tmp = tmp->nxt;
			continue;
		}
		val += dfs(tmp->e);
		tmp = tmp->nxt;
	}
	num[x] = val;
	return val;
}

int main() {
	int n, r, q, u, v, k;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &r, &q);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		tmp = (node*)malloc(sizeof(node));
		tmp->e = v;
		tmp->nxt = arr[u];
		arr[u] = tmp;

		tmp = (node*)malloc(sizeof(node));
		tmp->e = u;
		tmp->nxt = arr[v];
		arr[v] = tmp;
	}
	dfs(r);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &k);
		printf("%d\n", num[k]);
	}

	return 0;
}
