#include <stdio.h>


void change(char num[]);

int main() {
	char a[4], b[4];
	int i;
	scanf("%s %s", a, b);
	change(a);
	change(b);
	for (i = 0; i < 4; i++) {
		if (a[i] > b[i]) {
			printf("%s\n", a);
			break;
		}
		else if (a[i] < b[i]) {
			printf("%s\n", b);
			break;
		}
	}
	return 0;
}

void change(char num[]) {
	char tmp;
	tmp = num[0];
	num[0] = num[2];
	num[2] = tmp;
}