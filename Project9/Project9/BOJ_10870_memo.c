#include <stdio.h>

int main() {
	int n, i, arr[21] = {0,};
	scanf("%d", &n);
	arr[1] = arr[2] = 1;
	for (i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%d\n", arr[n]);
	return 0;
}