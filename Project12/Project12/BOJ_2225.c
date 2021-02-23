#include <stdio.h>

#define limit 1000000000

int main() {
	int n, k;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	int arr[201][201];
	for (int i = 0; i <= k; i++) {
		arr[i][0] = 1;
	}
	for (int j = 0; j <= n; j++) {
		arr[0][j] = 1;
	}
	for (int i = 1; i < k; i++)	{
		for (int j = 1; j <= n; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			arr[i][j] %= limit;
		}
	}
	printf("%d\n", arr[k - 1][n]);
	return 0;
}
