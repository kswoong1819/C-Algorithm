#include <stdio.h>

int main() {
	int n;
	int a, b;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}
	return 0;
}