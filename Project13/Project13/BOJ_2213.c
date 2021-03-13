#include <stdio.h>
#include <malloc.h>

#define MaxSz 1000001
#define max(a,b) (a>b ? a : b)

typedef struct nd {
	int e;
	struct nd* nxt;
}node;

node* arr[MaxSz];
int dp[MaxSz][2];
int visited[MaxSz] = { 0, };

int dfs(int k) {
	node* tmp = arr[k];
	visited[k] = 1;
	while (tmp) {
		if (visited[tmp->e]) {
			tmp = tmp->nxt;
			continue;
		}
		dfs(tmp->e);
		dp[k][0] += dp[tmp->e][1];
		dp[k][1] += max(dp[tmp->e][0], dp[tmp->e][1]);
		tmp = tmp->nxt;
	}
}

int main() {
	int n, v, u;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &v, &u);
		tmp = (node*)malloc(sizeof(node));
		tmp->e = v;
		tmp->nxt = arr[u];
		arr[u] = tmp;

		tmp = (node*)malloc(sizeof(node));
		tmp->e = u;
		tmp->nxt = arr[v];
		arr[v] = tmp;
	}
	dfs(1);
	printf("%d\n", n - max(dp[1][0], dp[1][1]));
	return 0;
}