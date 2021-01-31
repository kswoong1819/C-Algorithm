#include <stdio.h>

int main() {
	int n, cnt = 1,result = 666;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (1)
	{
		if (n == cnt) {
			printf("%d\n", result);
			break;
		}
		else {
			result++;
			int tmp = result;
			while (tmp >= 666) {
				if (tmp % 1000 == 666) {
					cnt++;
					break;
				}
				tmp /= 10;
			}
		}
	}
	return 0;
}