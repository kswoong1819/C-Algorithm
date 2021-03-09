#include <stdio.h>

long long arr[1000001];

int main() {
	long long  n, m;
	long long  min_len = 0, max_len = 0, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (max_len < arr[i])
			max_len = arr[i];
	}
	while (min_len <= max_len) {
		int mid = (min_len + max_len) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] - mid > 0)
				tmp += arr[i] - mid;
		}
		if (tmp >= m) {
			if (result < mid)
				result = mid;
			min_len = mid + 1;
		}
		else {
			max_len = mid - 1;
		}
	}
	printf("%lld\n", result);
	return 0;
}
