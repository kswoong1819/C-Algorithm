#include <stdio.h>

int main() {
	int A, B;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &A, &B);
	printf("%d\n", A-B);
	return 0;
}