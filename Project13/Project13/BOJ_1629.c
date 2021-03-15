#include <stdio.h>

int main() {
	long long a, b, c;
	long long ans = 1;
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld %lld", &a, &b, &c);
	while (b > 0) {
		if ((b % 2) == 1)
			ans = (a * ans) % c;
		a *= a;
		b /= 2;
		a = a % c;
	}
	printf("%lld\n", ans);
	return 0;
}