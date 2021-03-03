#include <stdio.h>
#include <malloc.h>

#define MaxSz 200001

typedef struct nd {
	int e, cnt;
	struct nd* nxt;
}node;

node* arr[MaxSz];
int value[MaxSz];
int visited[MaxSz] = { 0, };

int max(int* dp) {
	int val = 0;
	for (int i = 1; i <= dp[0] + 1; i++) {
		if (val < dp[i])
			val = dp[i];
	}
	return val;
}

void dfs(int k, int** dp) {
	node* tmp = arr[k];
	visited[k] = 1;
	while (tmp) {
		if (visited[tmp->e]) {
			tmp = tmp->nxt;
			continue;
		}
		dfs(tmp->e, dp);
		dp[k][tmp->cnt] += value[k] * value[tmp->e];
		dp[k][tmp->cnt] += dp[tmp->e][dp[tmp->e][0] + 1];
		int m = max(dp[tmp->e]);
		if (m > 0) {
			for (int i = 1; i <= dp[k][0] + 1; i++) {
				if (tmp->cnt == i)
					continue;
				dp[k][i] += m;
			}
		}
		tmp = tmp->nxt;
	}
}

int main() {
	int n, v;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	dp[1] = (int*)calloc(10, sizeof(int));
	for (int i = 2; i <= n; i++) {
		scanf("%d", &v);
		dp[i] = (int*)calloc(10, sizeof(int));
		dp[v][0]++;
		tmp = (node*)malloc(sizeof(node));
		tmp->e = i;
		tmp->cnt = dp[v][0];
		tmp->nxt = arr[v];
		arr[v] = tmp;

		tmp = (node*)malloc(sizeof(node));
		tmp->e = v;
		tmp->cnt = dp[v][0];
		tmp->nxt = arr[i];
		arr[i] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
		if (dp[i][0] + 1 >= 10) {
			realloc(dp[i], sizeof(int) * (dp[i][0] + 1));
			for (int j = 1; j <= dp[i][0] + 1; j++) {
				dp[i][j] = 0;
			}
		}
	}
	dfs(1, dp);
	printf("%d", max(dp[1]));

	for (int i = 1; i <= n; i++)
		free(dp[i]);
	free(dp);

	return 0;
}
