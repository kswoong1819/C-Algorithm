#include <stdio.h>

int main() {
	long long n, k, q, x, y;
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld %lld", &n, &k, &q);
	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &x, &y);
		long long cnt = 0;
		if (k == 1) {
			cnt = x > y ? x - y : y - x;
			printf("%lld\n", cnt);
			continue;
		}
		while (x != y) {
			cnt++;
			if (x > y) {
				x = (x - 2) / k + 1;
			}
			else {
				y = (y - 2) / k + 1;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}