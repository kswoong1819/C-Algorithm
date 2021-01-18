#include <stdio.h>

int main() {
	int A, B;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &A, &B);
	if (A < B) printf("<");
	else if (A > B) printf(">");
	else printf("==");
}