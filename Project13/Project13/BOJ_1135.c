#include <stdio.h>

int count[51] = { 0, };

int main() {
	int n, p;
	int tmp[51];
	int flag[51] = { 0, };
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &p);
	tmp[0] = p;
	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp[i]);
	}
	for (int i = n-1; i > 0; i--) {
		if (count[i] == 0 && !flag[tmp[i]])
			count[tmp[i]]++;
		else if (count[tmp[i]] < count[i] + 1) {
			count[tmp[i]] = count[i] + 1;
			flag[tmp[i]] = 1;
		}
		else if (count[tmp[i]] == count[i] + 1) {
			count[tmp[i]]++;
			flag[tmp[i]] = 1;
		}
	}
	printf("%d\n", count[0]);
	return 0;
}
