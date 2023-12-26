#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[3][10001]; // 타일 문제 처럼 해당 행에 어느부분을 채우는가로 나누어야한다.
int map[10001][2];
int n, w;

const int INF = 987654321;

void solve() {
	// 2열부터 시작해야함.
	// 그러려면 1열까진 내용을 다 채워놔야겠지
	for (int i = 2; i <= n; ++i) {
		// 기본값 세팅
		dp[0][i] = dp[2][i - 1] + 1;
		dp[1][i] = dp[2][i - 1] + 1;
		if (map[i][0] + map[i][1] <= w) {
			dp[2][i] = dp[2][i - 1] + 1;
		}
		else dp[2][i] = dp[2][i - 1] + 2;
		if (map[i - 1][0] + map[i][0] <= w && map[i - 1][1] + map[i][1] <= w) {
			dp[2][i] = min(dp[2][i], dp[2][i - 2] + 2);
		}

		if (map[i][0] + map[i - 1][0] <= w) {
			dp[0][i] = min(dp[0][i], dp[1][i - 1] + 1);
		}
		if (map[i][1] + map[i - 1][1] <= w) {
			dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
		}
		
		dp[2][i] = min(dp[2][i], min(dp[1][i] + 1, dp[0][i] + 1));
	}
}

int main() {
	cout.tie(0); cin.tie(0)->sync_with_stdio(0);
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> w;
		
		for (int j = 0; j < 2; ++j) {
			for (int i = 1; i <= n; ++i) {
				cin >> map[i][j];
			}
		}
		int ans;
		// 시작 case 4개.
		
		// 끝 - 시작 부분에 특수부대를 걸치지 않은 경우
		for (int i = 0; i < 3; ++i)
			memset(dp[i], 0, sizeof(dp[i]));
		dp[1][1] = dp[0][1] = 1; // 쌩으로 하나 채운 경우
		if (map[1][0] + map[1][1] <= w) {
			dp[2][1] = 1;
		}
		else dp[2][1] = 2;
		solve();
		ans = dp[2][n];

		// 위에 만 걸친 경우
		if (map[1][0] + map[n][0] <= w) {
			for (int i = 0; i < 3; ++i)
				memset(dp[i], 0, sizeof(dp[i]));
			dp[0][1] = 0; // 초기 상태가 이미 dp[0][1] 이다.
			dp[1][1] = INF; // 이곳을 참조할 경우의 수가 없다.
			dp[2][1] = 1;
			solve();
			ans = min(ans, dp[1][n] + 1);
		}
		if (map[1][1] + map[n][1] <= w) {
			for (int i = 0; i < 3; ++i)
				memset(dp[i], 0, sizeof(dp[i]));
			dp[0][1] = INF; // 불가능
			dp[1][1] = 0;
			dp[2][1] = 1;
			solve();
			ans = min(ans, dp[0][n] + 1);
		}
		if (map[1][0] + map[n][0] <= w && map[1][1] + map[n][1] <= w) {
			for (int i = 0; i < 3; ++i)
				memset(dp[i], 0, sizeof(dp[i]));
			dp[0][1] = dp[1][1] = INF; // 불가능
			dp[2][1] = 0;
			solve();
			ans = min(ans, dp[2][n - 1] + 2);
		}
		cout << ans << '\n';
	}

}