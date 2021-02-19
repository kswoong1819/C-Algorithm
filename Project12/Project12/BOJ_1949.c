#include <stdio.h>
#include <malloc.h>

#define max(a, b) (a > b ? a : b)

void vector(int** arr, int x, int y) {
	if (arr[x][0] <= arr[x][1]) {
		arr[x][0] *= 2;
		realloc(arr[x], sizeof(int) * arr[x][0]);
	}
	arr[x][arr[x][1]++] = y;
	return;
}

void dfs(int k, int** arr, int** dp, int* visited) {
	visited[k] = 1;
	for (int i = 2; i <= arr[k][1]; i++) {
		int nxt = arr[k][i];
		if (nxt <= 0) break;
		if (visited[nxt] == 1) continue;
		dfs(nxt, arr, dp, visited);
		dp[k][0] += dp[nxt][1];
		dp[k][1] += max(dp[nxt][0], dp[nxt][1]);
	}
	return;
}

int main() {
	int n, a, b;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int* town = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &town[i]);
	}
	int** arr = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i < n + 1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 100);
		arr[i][0] = 100;
		arr[i][1] = 2;
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		vector(arr, a, b);
		vector(arr, b, a);
	}

	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i < n + 1; i++) {
		dp[i] = (int*)malloc(sizeof(int) * 2);
		dp[i][0] = town[i];
		dp[i][1] = 0;
	}

	int* visited = (int*)malloc(sizeof(int) * (n + 1));

	dfs(1, arr, dp, visited);

	printf("%d\n", max(dp[1][0], dp[1][1]));

	for (int i = 1; i < n + 1; i++) {
		free(arr[i]);
		free(dp[i]);
	}
	free(arr);
	free(town);
	free(dp);
	free(visited);
	return 0;
}
