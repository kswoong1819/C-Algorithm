#include <stdio.h>
#include <malloc.h>

#define Ms 1001
#define INF 10e10
#define min(a,b) (a>b ? b : a)

int arr[Ms][Ms] = { 0, };
int dp[Ms][101];

void bfs(int st) {

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
	bfs(1);

	return 0;
}
