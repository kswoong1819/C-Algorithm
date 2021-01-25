#include <stdio.h>

int cal(int n);

int main() {
	int num;
	int arr[10001] = { 0 };
	for (int i = 1; i < 10001; i++)
	{
		num = cal(i);
		arr[num] = 1;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (arr[i] != 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}

int cal(int n) {
	int nxt = n;
	while (n > 0) {
		nxt += n % 10;
		n /= 10;
		if (nxt > 10000) return 0;
	}
	return nxt;
}