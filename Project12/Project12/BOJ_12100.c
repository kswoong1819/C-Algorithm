#include <stdio.h>

int n;
int result = 0;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void move(int map[21][21], int d) {
	int ni, nj, nr, nc, tmp;
	for (int i = 0; i < n; i++) {
		ni = i;
		if (d == 1) {
			ni = n - i - 1;
		}
		for (int j = 0; j < n; j++) {
			nj = j;
			if (d == 0) {
				nj = n - j - 1;
			}
			if (map[ni][nj] > 0) {
				nr = ni;
				nc = nj;
				tmp = map[nr][nc];
				map[nr][nc] = 0;
				while (1) {
					nr += dr[d];
					nc += dc[d];
					if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
						if (map[nr][nc] == 0)
							continue;
						if (tmp == map[nr][nc]) {
							tmp += tmp;
							map[nr - dr[d]][nc - dc[d]] = 0;
						}
						else {
							map[nr - dr[d]][nc - dc[d]] = tmp;
							break;
						}
					}
					else {
						map[nr - dr[d]][nc - dc[d]] = tmp;
						break;
					}
				}
			}
		}
	}
	return;
}

void copyarr(int tmp_map[21][21], int map[21][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
	return;
}

void findmax(int map[21][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (result < map[i][j]) {
				result = map[i][j];
			}
		}
	}
	return;
}

void go(int map[21][21], int k, int ch) {
	if (k >= 4) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ch == i) continue;
		int tmp_map[21][21];
		copyarr(tmp_map, map);
		move(tmp_map, i);
		findmax(tmp_map);
		go(tmp_map, k + 1, i);
	}
}

int main() {
	int map[21][21];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	go(map, 0, -1);
	printf("%d\n", result);
}
