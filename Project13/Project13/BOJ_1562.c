#include<stdio.h>

#define MOD 1000000000

int dp[110][10][4];

int main() {
	int N, i, j, k, s = 0;
	scanf("%d", &N);
	for (j = 1; j < 9; j++)
		dp[1][j][0] = 1;
	dp[1][0][1] = 1;
	dp[1][9][2] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k < 4; k++) {
				if (j > 0 && j < 9) {
					dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
				}
				else if (j) {
					if (k == 2)
						dp[i][j][k] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2]) % MOD;
					if (k == 3)
						dp[i][j][k] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][3]) % MOD;
				}
				else {
					if (k == 1)
						dp[i][j][k] = (dp[i - 1][j + 1][0] + dp[i - 1][j + 1][1]) % MOD;
					if (k == 3)
						dp[i][j][k] = (dp[i - 1][j + 1][2] + dp[i - 1][j + 1][3]) % MOD;
				}
			}
		}
	}
	for (j = 1; j <= 9; j++)
		s = (s + dp[N][j][3]) % MOD;
	printf("%d", s);
}