#include <stdio.h>

#define max(a, b) (a>b ? a : b)

int n, tmp;
int stair[310][3];

void dfs(int cur, int step, int k) {
	if (k > n) return;
	if (step == 1) {
		tmp = cur + stair[k][0];
		if (stair[k][2] >= tmp) return;
		stair[k][2] = max(stair[k][2], tmp);
		dfs(tmp, 2, k+1);
		tmp = cur + stair[k+1][0];
		if (stair[k + 1][1] >= tmp) return;
		stair[k + 1][1] = max(stair[k+1][1], tmp);
		dfs(tmp, 1, k+2);
	}
	else {
		tmp = cur + stair[k + 1][0];
		if (stair[k + 1][1] >= tmp) return;
		stair[k+1][1] = max(stair[k+1][1], tmp);
		dfs(tmp, 1, k+2);
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	{
		scanf("%d", &stair[i][0]);
	}
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	printf("%d\n", max(stair[n][1], stair[n][2]));
	return 0;
}