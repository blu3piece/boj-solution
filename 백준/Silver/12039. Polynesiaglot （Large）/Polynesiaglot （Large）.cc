#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {

        long long dp[501] = {
            0,
        };
        int c, v, l;
        cin >> c >> v >> l;
        c *= v;
        dp[1] = v;
        dp[2] = c;
        dp[2] += v * v;
        for (int i = 3; i <= l; ++i) {
            dp[i] += dp[i - 1] * v;
            dp[i] %= 1000000007;
            dp[i] += dp[i - 2] * c;
            dp[i] %= 1000000007;
        }
        cout << "Case #" << tc << ": ";
        cout << dp[l] << '\n';
    }
}