#include <stdio.h>

int main() {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		puts("");
	}
	return 0;
}