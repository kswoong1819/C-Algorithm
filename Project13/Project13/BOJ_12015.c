#include <stdio.h>
#include <malloc.h>
int b = 10000000000;

int main() {
	int n, a, tmp, p = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	int* arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (arr[p] < a)
			arr[++p] = a;
		else {
			int s = 1;
			int e = p;
			int idx = (s + e) / 2;
			while (s <= e) {
				int mid = (s + e) / 2;
				if (arr[mid] >= a) {
					idx = mid;
					e = mid - 1;
				}
				else {
					s = mid + 1;
				}
			}
			if (arr[idx] > a)
				arr[idx] = a;
		}
	}
	free(arr);

	printf("%d", p);
	return 0;
}