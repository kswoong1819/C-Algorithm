#include <stdio.h>

#define LEN 10001
#define max(a, b) (a>b ? a : b)

int n, a, b;
int visited[LEN];
int map[LEN][LEN];
int dp1[LEN][LEN];
int dp2[LEN][LEN];

void check(int k) {
	visited[k] = 1;
	int t = 2;
	for (int i = 1; i <= LEN; i++) {
		int nxt = map[k][i];
		if (nxt <= 0) break;
		if (visited[nxt] == 1) continue;
		check(nxt);
		dp1[k][0] += dp2[nxt][0];
		dp2[k][0] += max(dp1[nxt][0], dp2[nxt][0]);
		t = 2;
		while (1) {
			if (dp2[nxt][t] <= 0) break;
			dp1[k][dp1[k][1]++] += dp2[nxt][t++];
		}
		t = 2;
		if (max(dp1[nxt][0], dp2[nxt][0]) == dp1[nxt][0]) {
			while (1) {
				if (dp1[nxt][t] <= 0) break;
				dp2[k][dp2[k][1]++] += dp1[nxt][t++];
			}
		}
		else {
			while (1) {
				if (dp2[nxt][t] <= 0) break;
				dp2[k][dp2[k][1]++] += dp2[nxt][t++];
			}
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp1[i][0]);
		dp1[i][2] = i;
		dp1[i][1] = 3;
		dp2[i][1] = 2;
		map[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		map[a][map[a][0]++] = b;
		map[b][map[b][0]++] = a;
	}
	check(1);
	printf("%d\n", max(dp1[1][0], dp2[1][0]));
	if (max(dp1[1][0], dp2[1][0]) == dp1[1][0]) {
		for (int i = 2; i < LEN; i++) {
			if (dp1[1][i] <= 0) break;
			printf("%d ", dp1[1][i]);
		}
	} else {
		for (int i = 2; i < LEN; i++) {
			if (dp2[1][i] <= 0) break;
			printf("%d ", dp2[1][i]);
		}
	}
	return 0;
}
