#include <stdio.h>

#define MaxSz 1002

int arr[MaxSz][2];
int sorted[MaxSz][2];

void merge(int st, int mid, int ed) {
	int i = st;
	int j = mid + 1;
	int k = st;

	while (i <= mid && j <= ed) {
		if (arr[i][1] <= arr[j][1]) {
			sorted[k][0] = arr[i][0];
			sorted[k++][1] = arr[i++][1];
		}
		else {
			sorted[k][0] = arr[j][0];
			sorted[k++][1] = arr[j++][1];
		}
	}
	if (i > mid) {
		for (int t = j; t <= ed; t++) {
			sorted[k][0] = arr[t][0];
			sorted[k++][1] = arr[t][1];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k][0] = arr[t][0];
			sorted[k++][1] = arr[t][1];
		}
	}
	for (int t = st; t <= ed; t++) {
		arr[t][0] = sorted[t][0];
		arr[t][1] = sorted[t][1];
	}
}

void merge_sort(int st, int ed) {
	if (st < ed) {
		int mid = (st + ed) / 2;
		merge_sort(st, mid);
		merge_sort(mid + 1, ed);
		merge(st, mid, ed);
	}
}

int main() {
	int n, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i][1]);
		arr[i][0] = i;
	}
	merge_sort(1, n);
	for (int i = 1; i <= n; i++) {
		result += arr[i][1] * (n - i + 1);
	}
	printf("%d\n", result);
	return 0;
}
