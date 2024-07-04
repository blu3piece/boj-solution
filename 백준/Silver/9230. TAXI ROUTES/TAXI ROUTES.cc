#include <cstring>
#include <iostream>
using namespace std;

int dp[31][31];
bool v[31][31];

int get_route(int y, int x) {
    if (y < 0 || x < 0)
        return 0;
    if (y == 0 && x == 0) {
        return 1;
    }
    if (v[y][x])
        return dp[y][x];
    v[y][x] = true;
    return dp[y][x] = get_route(y - 1, x) + get_route(y, x - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int tc = 0;
    while (++tc) {
        int m, n;
        cin >> m >> n;
        if (!m && !n)
            break;
        memset(v, false, sizeof(v));
        memset(dp, 0, sizeof(dp));

        while (1) {
            int x, y;
            cin >> x >> y;
            if (!x && !y)
                break;
            v[y][x] = true;
        }

        cout << "Map " << tc << ": " << get_route(n - 1, m - 1) << '\n';
    }
}