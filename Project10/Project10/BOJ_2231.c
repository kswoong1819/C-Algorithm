#include <stdio.h>

int check(int n) {
	for (int i = 1; i < n; i++)
	{
		int total = i, num = i;
		while (num > 0)
		{
			total += num % 10;
			num /= 10;
		}
		if (total == n) return i;
	}
	return 0;
}

int main() {
	int n, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	result = check(n);
	printf("%d\n", result);
	return 0;
}