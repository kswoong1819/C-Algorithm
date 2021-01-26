#include <stdio.h>

int main() {
	int a, b, c;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &a, &b, &c);
	if (b >= c) {
		printf("-1");
		return 0;
	}
	int cnt = a / (c - b) + 1;
	printf("%d", cnt);
	return 0;
}