#include <stdio.h>

int main() {
	int n, step = 1;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n > 1)
	{
		n -= 6 * step;
		step++;
	}
	printf("%d", step);
	return 0;
}