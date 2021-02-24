#include <stdio.h>

#define LEN 501

int m, n;
int arr[LEN][LEN];
int dp[LEN][LEN];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int dfs(int r, int c) {
	int nr, nc;
	if (r == m - 1 && c == n - 1)
		return 1;
	if (dp[r][c] == -1) {
		dp[r][c] = 0;
		for (int i = 0; i < 4; i++)	{
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr >= 0 && nr < m && nc >= 0 && nc < n && arr[r][c] > arr[nr][nc]) {
				dp[r][c] += dfs(nr, nc);
			}
		}
	}
	return dp[r][c];
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dfs(0, 0);
	printf("%d\n", dp[0][0]);
	return 0;
}
