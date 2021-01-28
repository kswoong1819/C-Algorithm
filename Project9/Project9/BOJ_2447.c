#include <stdio.h>

#define size 3000

char stars[size][size] = { NULL };

int point(int n, int m) {
	if (m == n * 3)
		return 0;
	else {
		if (m == 3) {
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++) {
					if (i % 3 == 1 && j % 3 == 1)
						stars[i][j] = ' ';
					else continue;
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (m / 3 <= i && i < 2 * m / 3 && m / 3 <= j && j < 2 * m / 3)
						stars[i][j] = ' ';
					else
						stars[i][j] = stars[i % m][j % m];
				}
			}
		}
		point(n, m * 3);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			stars[i][j] = '*';
		}
	}
	point(n, 3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", stars[i][j]);
		}
		printf("\n");
	}
	return 0;
}