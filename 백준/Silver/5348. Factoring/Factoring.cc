#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        long long d = n;
        long long p = 2;
        cout << n << ": ";
        while (p * p <= n && d > 1) {
            while (!(d % p)) {
                d /= p;
                cout << p << ' ';
            }
            p++;
        }
        if (n == d)
            cout << "prime";
        else if (d != 1)
            cout << d << ' ';
        cout << '\n';
    }
}