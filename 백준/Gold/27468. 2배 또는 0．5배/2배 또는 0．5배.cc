#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> used; // Check used 0 ~ N-1
int N;
int ans[2000000];
int it[2][4] = {{1, 2, 4, 3}, {1, 3, 2, 4}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin >> N;
    cout << "YES\n";
    int num = 1;
    int iterations = N / 4; // 1 3 2 4 ...
    for (int i = 0; i < iterations; ++i) {
        int t = i * 4;
        for (int j = 0; j < 4; ++j) {
            cout << t + it[N % 2][j] << ' ';
        }
    }
    int i = iterations * 4 + 1;
    while (i <= N) {
        cout << iterations * 4 + it[N % 2][(i - 1) % 4] << ' ';
        ++i;
    }
}