#include <stdio.h>

int main() {
	int a, b;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &a, &b);
	b += a * 60;
	b -= 45;
	if (b < 0) {
		b += 24 * 60;
	}
	a = b / 60;
	b %= 60;
	printf("%d %d", a, b);

	return 0;
}