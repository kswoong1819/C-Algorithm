#include <stdio.h>

int main() {
	double A, B;

	freopen("input.txt", "r", stdin);

	scanf("%lf %lf", &A, &B);
	printf("%.9lf\n", A/B);
	return 0;
}