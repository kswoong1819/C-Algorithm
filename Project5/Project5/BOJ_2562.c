#include <stdio.h>

int main() {
	int num, i;
	int max = 0, idx = 1;
	freopen("input.txt", "r", stdin);
	for (i = 1; i <= 9; i++)
	{
		scanf("%d", &num);
		if (max < num)
		{
			max = num;
			idx = i;
		}
	}
	printf("%d\n%d", max, idx);
	return 0;
}