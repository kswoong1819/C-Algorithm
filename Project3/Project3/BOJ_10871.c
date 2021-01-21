#include <stdio.h>

int main() {
	int n, x, num;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num < x) printf("%d ", num);
	}
	return 0;
}