#include <stdio.h>

int main() {
	int n, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		result += i;
	}
	printf("%d\n", result);
	return 0;
}