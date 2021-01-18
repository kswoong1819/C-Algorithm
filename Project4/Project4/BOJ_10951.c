#include <stdio.h>

int main() {
	int a, b;
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
	return 0;
}