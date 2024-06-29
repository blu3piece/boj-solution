#include <iostream>
using namespace std;

int price[6];
int auctions[100001];
int n, k;

bool selected[6];

int solve(int s) {
    if (s == 6) {
        int ans = 0;
        int money = k;
        for (int i = 0; i < n; ++i) {
            if (selected[auctions[i] - 1] && money >= price[auctions[i] - 1]) {
                ans++;
                money -= price[auctions[i] - 1];
            }
        }
        return ans;
    }

    int mx = 0;
    for (int i = s; i < 6; ++i) {
        selected[i] = true;
        int v1 = solve(i + 1);
        selected[i] = false;
        if (i == 5) { // 마지막 부분만 최적화
            int v2 = solve(i + 1);
            v1 = v2 > v1 ? v2 : v1;
        }

        mx = mx > v1 ? mx : v1;
    }
    return mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < 6; ++i) {
        cin >> price[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> auctions[i];
    }
    cout << solve(0);
}