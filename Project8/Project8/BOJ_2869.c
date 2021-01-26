#include <stdio.h>

int main() {
	int a, b, v;
	int day = 1;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &a, &b, &v);
	day += (v - a) / (a - b);
	if ((v - a) % (a - b) > 0) day++;
	printf("%d", day);
	return 0;
}