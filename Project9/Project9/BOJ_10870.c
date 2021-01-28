#include <stdio.h>

int fibo(int n) {
	if (n > 1) {
		return fibo(n - 2) + fibo(n - 1);
	}
	else {
		return n;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
	return 0;
}