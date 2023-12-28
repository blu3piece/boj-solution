#include<iostream>
using namespace std;

int board[500][500];
int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{0, -1},
	{1, 0}
};
int dp[500][500];
int n, m;

int dfs(int y, int x) {
	int val = 0;
	if (dp[y][x] > -1) {
		return dp[y][x];
	}
	for (int i = 0; i < 4; ++i) {
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
		if (board[dy][dx] > board[y][x]) {
			val += dfs(dy, dx);
		}
	}
	return dp[y][x] = val;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1; // 출발점에서 출발점으로 가는 길은 1개 (자신 그자체)
	dfs(n-1, m-1);
	cout << dp[n-1][m-1];
}