#include<iostream>
using namespace std;

int dp[2001]; // 결과값
bool pd[2001][2001]; // 팰린드롬
const int INF = 987654321;

int main() {

	string buf; cin >> buf;
	int n = buf.size();
	buf = " " + buf;
	
	for (int i = 1; i <= n; ++i) {
		pd[i][i] = true;
		if (i == n) continue;
		if (buf[i] == buf[i + 1]) {
			pd[i][i + 1] = true;
			pd[i + 1][i] = true;
		}
	}

	for (int i = 2; i < n; ++i) {
		for (int j = 1; j <= n - i; ++j) {
			if (buf[j] == buf[j + i] && pd[j + 1][j + i - 1]) {
				pd[j + i][j] = pd[j][j + i] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (pd[i][j]) {
				if (dp[i] == 0 || dp[i] > dp[j - 1] + 1) {
					dp[i] = dp[j - 1] + 1;
				}
			}
		}
	}
	
	cout << dp[n];
}