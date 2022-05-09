#include <stdio.h>
#include <malloc.h>

int main() {
	int n, fst=0, nxt=1;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int* result = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	while (fst < n) {
		int a = arr[fst];
		// result[fst] = result[fst];
		for (int i = fst+1; i < n; i++) {
			if (arr[fst] > arr[i])
				result[i] = fst + 1;
			else
				break;
		}
		while (1) {
			if (arr[nxt] < arr[nxt+1] && a > arr[nxt + 1])
				result[nxt++] = result[nxt];
			else
				break;
		}int* 
		fst = nxt++;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	free(arr);
	free(result);

	return 0;
}
