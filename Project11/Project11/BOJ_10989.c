#include <stdio.h>

#define size 10001

int main() {
	int n, num;
	int count[size] = { 0, };
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		count[num]++;
	}

	for (int i = 0; i <= size; i++) {
		if (count[i] == 0) continue;
		for (int j = 0; j < count[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}