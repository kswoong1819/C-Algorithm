#include <stdio.h>

int main() {
	char str[16];
	int i, num, result = 0;
	scanf("%s", str);
	for (i = 0; i < strlen(str); i++) {
		num = str[i] - 'A';
		if (num < 15) {
			num /= 3;
		}
		else if (num >= 15 && num <= 18) {
			num = (num + 1) / 4 + 1;
		}
		else if (num >= 19 && num <= 21) {
			num = (num - 1) / 3;
		}
		else {
			num = (num + 2) / 4 + 1;
		}
		result += num + 3;
	}
	printf("%d", result);
	return 0;
}