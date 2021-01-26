#include <stdio.h>

int main() {
	int n, a, b;
	int line = 1;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n > line)
	{
		n -= line;
		line++;
	}
	a = line - (n - 1);
	b = n;
	if (line % 2) {
		printf("%d/%d", a, b);
	}
	else {
		printf("%d/%d", b, a);
	}
	return 0;
}