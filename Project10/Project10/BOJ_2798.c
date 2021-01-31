#include <stdio.h>

int max = 0;
int n, m;
int arr[101], used[101];

int choice(int k, int sum) {
	if (sum > m) {
		return 0;
	}
	if (k == 3) {
		if (sum > max) {
			max = sum;
		}
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			used[i] = 1;
			choice(k + 1, sum + arr[i]);
			used[i] = 0;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	 for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	choice(0, 0);
	printf("%d\n", max);
	return 0;
}