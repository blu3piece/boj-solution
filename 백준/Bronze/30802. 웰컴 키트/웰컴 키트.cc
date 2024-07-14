#include <iostream>
using namespace std;

int arr[6];

int main() {
    int n, t, p;
    cin >> n;
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i];
    }
    cin >> t >> p;
    int ans_t = 0;
    for (int i = 0; i < 6; ++i) {
        ans_t += arr[i] / t;
        if (arr[i] % t) {
            ans_t++;
        }
    }
    cout << ans_t << '\n' << n / p << ' ' << n % p;
}