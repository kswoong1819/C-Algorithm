#include <stdio.h>

int main() {
	int a, b;
	freopen("input.txt", "r", stdin);
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		printf("%d\n", a + b);
	}
	return 0;
}