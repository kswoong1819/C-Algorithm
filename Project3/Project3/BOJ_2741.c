#include <stdio.h>

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}