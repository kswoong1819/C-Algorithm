#include <stdio.h>
#include <malloc.h>

#define Ms 1001
#define INF 999999999
#define min(a,b) (a>b ? b : a)
#define swap(a,b) {int t=a; a=b; b=t;}

int arr[Ms][Ms] = { 0, };
int dp[Ms][101];

void bfs(int n, int k, int st) {
	int queue[Ms * 4];
	int front = 0, rear = 0, flag = 0;
	queue[rear++] = st;
	while (front < rear) {
		int q = queue[front++];
		for (int i = 1; i <= n; i++) {
			if (arr[q][i] > 0) {
				int tmp = dp[q][k-1] + arr[q][i];
				for (int j = 1; j <= k; j++) {
					if (dp[i][k-1] > tmp && dp[i][k-1] != tmp) {
						swap(dp[i][j], tmp);
						flag = 1;
					}
				}
				if (flag) {
					queue[rear++] = i;
					flag = 0;
				}
			}
		}
	}
	return;
}

int main() {
	int n, m, k, s, e, c;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &s, &e, &c);
		arr[s][e] = c;
	}
	bfs(n, k, 1);
	for (int i = 1; i <= n; i++) {
		if (dp[i][k] == INF)
			printf("%d\n", -1);
		else
			printf("%d\n", dp[i][k]);
	}
	return 0;
}
