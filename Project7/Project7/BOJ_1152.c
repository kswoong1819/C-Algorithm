#include <stdio.h>

int main() {
    char str[1000001];
    int i, cnt = 0;
    scanf("%[^\n]s", str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (i > 0 && str[i - 1] != ' ')
                continue;
            else
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}