/**
 * vowel : consist of minimum 1 character.
 * consonant : consist of minimum 2 characters.
 * so this will be a combination problem, which consists of
 * consonant form : vowel * consonant, where its length is 2.
 * vowel form : vowel where its length is 1.
 * if 1 1 4, then consonant : 1, vowel form
 * 4 length character could be partitioned as `1 + 1 + 1 + 1`, `1 + 1 + 2`, `2 +
 * 2` but this partitions should consider orders. which means, for example,
 * `2+1+1` and `1+2+1` are different. this method could be implmented via
 * dynamic programming easily, i guess.
 */

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
