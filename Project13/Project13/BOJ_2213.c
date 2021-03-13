#include <stdio.h>
#include <malloc.h>

#define MaxSz 10002
#define max(a,b) (a>b ? a : b)

typedef struct nd {
	int e;
	struct nd* nxt;
}node;

node* arr[MaxSz];
int dp[MaxSz][2];
int visited[MaxSz] = { 0, };
int check[MaxSz] = { 0, };

void dfs(int k) {
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

void trace(int k, int f) {
	node* tmp = arr[k];
	visited[k] = 0;
	if (f && dp[k][0] > dp[k][1]) {
		check[k] = 1;
		f = 0;
	}
	else {
		f = 1;
	}
	while (tmp) {
		if (!visited[tmp->e]) {
			tmp = tmp->nxt;
			continue;
		}
		trace(tmp->e, f);
		tmp = tmp->nxt;
	}
}

int main() {
	int n, v, u;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i][0]);
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
	printf("%d\n", max(dp[1][0], dp[1][1]));
	if (max(dp[1][0], dp[1][1]) == dp[1][0]) {
		trace(1, 1);
	}
	else {
		trace(1, 0);
	}
	for (int i = 1; i <= n; i++) {
		if(check[i])
			printf("%d ", i);
	}
	return 0;
}