#include <stdio.h>

int dp[1000001] = { 0,0,1,1 };

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 4; i <= num; i++) {
		int min = dp[i - 1] + 1;
		if (i % 2 == 0 && min > dp[i / 2])
			min = dp[i / 2] + 1;
		if (i % 3 == 0 && min > dp[i / 3])
			min = dp[i / 3] + 1;
		dp[i] = min;
	}
	printf("%d\n", dp[num]);
	while (1) {
		printf("%d ", num);
		if (num == 1)
			break;
		int min = num - 1;
		if (num % 2 == 0 && dp[num / 2] < dp[min])
			min = num / 2;
		if (num % 3 == 0 && dp[num / 3] < dp[min])
			min = num / 3;
		num = min;
	}
}