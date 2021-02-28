#include <stdio.h>
#include <malloc.h>
#include <vector>
using namespace std;

#define MaxSz 200010

int n;
int value[MaxSz];
int visited[MaxSz];

int max(vector<int> &dp) {
	int x = 0, maxVal = 0;
	while (dp[x] > 0) {
		if (maxVal < dp[x])
			maxVal = dp[x];
		x++;
	}
	return maxVal;
}

void dfs(vector<vector<int>> &arr, vector<vector<int>> &dp, int k) {
	visited[k] = 1;
	for (int i = 0; i < arr[k].size(); i++) {
		int nxt = arr[k][i];
		if (nxt > n) return;
		if (visited[nxt] == 1) continue;
		dfs(arr, dp, nxt);
		dp[k][i] += value[k] * value[nxt];
		dp[k][i] += dp[nxt][arr[nxt].size()];
		int sum = max(dp[nxt]);
		for (int j = 0; j <= arr[k].size(); j++) {
			if (sum == 0) break;
			if (i == j)	continue;
			dp[k][j] += sum;
		}
	}
	return;
}

int main() {
	int num;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	vector<vector<int>> arr(n+1);
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for (int i = 2; i <= n; i++) {
		scanf("%d", &num);
		arr[num].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
	}

	dfs(arr, dp, 1);
	printf("%d\n", max(dp[1]));
	return 0;
}
