#include <stdio.h>

int main() {
	int A, B, C;
	freopen("input.txt", "r", stdin);
	scanf("%d", &A);
	scanf("%d", &B);
	int D = B;
	for (int i = 0; i < 3; i++)
	{
		C = D % 10;
		D = D / 10;
		printf("%d\n", A*C);
	}
	printf("%d\n", A * B);
	return 0;
}