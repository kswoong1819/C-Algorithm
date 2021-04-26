#include <stdio.h>
#include <math.h>

int n;
int check[21 * 21 + 1][5];
int arr[22][22] = { 0, };

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int insert(int d) {
	int nr, nc, cnt = 0, blank = 0;
	int re_x = 0, re_y = 0, re_cnt = 0, re_blank = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) continue;
			cnt = 0;
			blank = 0;
			for (int k = 0; k < 4; k++) {
				nr = i + dr[k];
				nc = j + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (!arr[nr][nc]) {
					blank++;
					continue;
				}
				for (int z = 0; z < 4; z++) {
					if (arr[nr][nc] == check[d][z]) {
						cnt++;
						break;
					}
				}
			}
			if (re_cnt < cnt) {
				re_cnt = cnt;
				re_blank = blank;
				re_x = i;
				re_y = j;
			}
			else if (re_cnt == cnt && re_blank < blank) {
				re_blank = blank;
				re_x = i;
				re_y = j;
			}
			else if (re_cnt == cnt && re_blank == blank) {
				if (re_x > i) {
					re_x = i;
					re_y = j;
				}
				else if (re_x == i && re_y > j) {
					re_x = i;
					re_y = j;
				}
			}
		}
	}
	printf("%d %d\n", re_x, re_y);
	arr[re_x][re_y] = d;
}

int main() {
	int c, nr, nc, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 1; i <= n * n; i++) {
		scanf("%d", &c);
		scanf("%d %d %d %d", &check[c][0], &check[c][1], &check[c][2], &check[c][3]);
		printf("%d ", i);
		if (i == 1) {
			arr[1][1] = c;
		}
		else if (i == n * n - 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!arr[i][j]) {
						arr[i][j] = c;
						printf("%d %d\n", i, j);
						break;
					}
				}
			}
		}
		else {
			insert(c);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d = arr[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				nr = i + dr[k];
				nc = j + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				for (int z = 0; z < 4; z++) {
					if (arr[nr][nc] == check[d][z]) {
						cnt++;
						break;
					}
				}
			}
			result += (int)pow(10, --cnt);
		}
	}
	printf("%d", result);
	return 0;
}