#include <stdio.h>

int main() {
	int num, n_num;
	int a, b, c;
	int cnt = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	n_num = num;
	while (1)
	{
		cnt++;
		a = n_num / 10;
		b = n_num % 10;
		c = (a + b) % 10;
		n_num = b * 10 + c;
		if (num == n_num) break;
	}
	printf("%d", cnt);
	return 0;
}