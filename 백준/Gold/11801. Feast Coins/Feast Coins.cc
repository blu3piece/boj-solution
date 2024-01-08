#include<iostream>
#include<vector>
using namespace std;

int main() {
	cout.tie(0); cin.tie(0)->sync_with_stdio(0);
	int tc_mx; cin >> tc_mx;
	for (int tc = 1; tc <= tc_mx; ++tc) {
		
		int n, s; cin >> s >> n;
		long long ans = 0;
		
		vector<pair<int, int>> coin;
		for (int i = 0; i < n; ++i) {
			int v, c; cin >> v >> c; // value, count
			coin.push_back({ v, c });
		}
		for (int i = 1; i <= s; ++i) {
			if (s % i) continue;
			vector<long long> dp(s + 1, 0);
			for (int j = 0; j < n; ++j) {
				if (coin[j].second < i) continue;
				long long adder = coin[j].first* i;
				if (adder > s) continue;
				for (int k = s - adder; k >= 0; --k) {
					if (dp[k]) {
						dp[k + adder] += dp[k];
					}
					if (k == 0) {
						dp[adder] += 1;
					}
				}
			}
			ans += dp[s];
		}
		cout << "Case " << tc << ": " << ans << '\n';
	}
}