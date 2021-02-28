#include <stdio.h>
#include <malloc.h>

#define MaxSz 200010

int n;
int value[MaxSz];
int visited[MaxSz];

void fullvector(int num, int** arr) {
	arr[num][0] += 100;
	realloc(arr[num], sizeof(int*) * arr[num][0]);
	return;
}

int max(int* dp) {
	int x = 1, maxVal = 0;
	while (dp[x] > 0) {
		if (maxVal < dp[x])
			maxVal = dp[x];
		x++;
	}
	return maxVal;
}

void dfs(int** arr, int** dp, int k) {
	visited[k] = 1;
	for (int i = 1; i < arr[k][1]; i++) {
		int nxt = arr[k][i+1];
		if (nxt < 0) return;
		if (visited[nxt] == 1) continue;
		dfs(arr, dp, nxt);
		dp[k][i] += value[k] * value[nxt];
		dp[k][i] += dp[nxt][arr[nxt][1] - 1];
		int sum = max(dp[nxt]);
		for (int j = 1; j < arr[k][1]; j++) {
			if (sum == 0) break;
			if (i == j)	continue;
			dp[k][j] += sum;
		}
	}
	return;
}

int main() {
	int num;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 100);
		arr[i][0] = 100;
		arr[i][1] = 2;
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &num);
		arr[num][arr[num][1]++] = i;
		if (arr[num][1] >= arr[num][0] - 1)
			fullvector(num, arr);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
	}
	int** dp = (int**)calloc((n + 1), sizeof(int*));
	for (int i = 1; i <= n; i++) {
		dp[i] = (int*)calloc(arr[i][1], sizeof(int));
	}

	dfs(arr, dp, 1);
	printf("%d\n", max(dp[1]));

	for (int i = 1; i <= n; i++) {
		free(arr[i]);
		free(dp[i]);
	}
	free(arr);
	free(dp);
	return 0;
}
