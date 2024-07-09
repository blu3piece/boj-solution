#include <cmath>
#include <iostream>
using namespace std;

int arr[100000];
int n;

int solve(int gap, int a) {
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        int b = arr[i];
        if (b - a == gap + 1) {
            b--;
            cnt++;
            a = b;
        } else if (b - a == gap - 1) {
            b++;
            cnt++;
            a = b;
        } else if (b - a == gap) {
            a = b;
        } else {
            return -1;
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (n == 1 || n == 2) {
        cout << 0;
        return 0;
    }
    int gap[9][2] = {{0, 0},  {0, 1},  {0, -1}, {1, 0},  {1, 1},
                     {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};

    int mx = -1;
    for (int i = 0; i < 9; ++i) {
        int ret = abs(gap[i][0]) + abs(gap[i][1]);

        int r = solve(arr[1] + gap[i][1] - (arr[0] + gap[i][0]),
                      arr[1] + gap[i][1]);

        if (r == -1)
            ret = -1;
        else
            ret += r;
        mx = (mx == -1 || (ret > 0 && mx > ret)) ? ret : mx;
        // cout << "ret : " << ret << '\n';
        // cout << "mx : " << mx << '\n';
    }
    cout << mx;
}