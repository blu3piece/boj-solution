#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int P, Q, A, B, C, D;
        cin >> P >> Q >> A >> B >> C >> D;
        long long coins = B * (P / A) + D * (Q / C);
        long long x = B * coins / (A + B);
        long long v1 =
            (x / B) *
            B; // x개만큼 바꿀 수 없기에 B 의 배수 단위로 묶어 보낸 것.
        long long v2 = v1 + B; // 반대쪽의 경우의 수도 살펴야함.
        v1 = min(coins - v1,
                 v1 * A / B + P % A); // v1*A/B 는 비트로 바뀐 최종 개수를 뜻함.
        v2 = min(coins - v2, v2 * A / B + P % A);
        x = max(v1, v2);
        cout << x << '\n';
    }
}