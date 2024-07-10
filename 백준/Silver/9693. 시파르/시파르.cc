#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int tc = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int ans = 0;
        while (n >= 5) {
            n /= 5;
            ans += n;
        }
        cout << "Case #" << tc++ << ": " << ans << '\n';
    }
}