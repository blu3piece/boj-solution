#include <algorithm>
#include <iostream>
using namespace std;

long long a[100000];
long long b[100000];

long long get_gcd(long long a, long long b) {
    if (b == 0) // 서로소 인 경우.
        return a;
    return get_gcd(b, a % b);
}

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n;
    long long ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ans = a[0] - b[0];
    for (int i = 1; i < n; ++i) {
        long long g = a[i] - b[i];
        ans = get_gcd(max(ans, g), min(ans, g));
    }
    cout << ans;
}