#include <stdio.h>
// #include <stdbool.h>

// bool check(int num);
int check(int num);

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (check(i)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}

int check(int num) {
	int a, b, init;
	a = num % 10;
	num /= 10;
	b = num % 10;
	num /= 10;
	init = a - b;
	while (num > 0) {
		a = b;
		b = num % 10;
		num /= 10;
		if (init != a - b) {
			return 0;
		}
	}
	return 1;
}