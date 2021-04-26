#include <stdio.h>
#include <math.h>

int n;
int check[21 * 21 + 1][5];
int arr[22][22] = { 0, };

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int insert(int d) {
	int nr, nc, cnt = 0, blank = 0;
	int re_x = -1, re_y = -1, re_cnt = 0, re_blank = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) continue;
			if (re_x == -1 && re_y == -1) {
				re_x = i;
				re_y = j;
			}
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
	arr[re_x][re_y] = d;
}

int main() {
	int c, nr, nc, result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 1; i <= n * n; i++) {
		scanf("%d", &c);
		scanf("%d %d %d %d", &check[c][0], &check[c][1], &check[c][2], &check[c][3]);
		if (i == 1) {
			arr[1][1] = c;
		}
		else if (i == n * n) {
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (flag) break;
				for (int j = 0; j < n; j++) {
					if (!arr[i][j]) {
						arr[i][j] = c;
						flag = 1;
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
			printf("%d\n", d);
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