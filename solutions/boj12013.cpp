#include<iostream>
#include<algorithm>
using namespace std;

int arr[249];
int dp[249][249];

/**
* 12013 248 게임
* 
* 무조건 선형으로 주어진 배열을 그대로 선형으로 나누어서는 안된다는 개념을 알게 해주는 문제이다.
* 간격을 좁은 순부터 순회하여 O(N^3) 에 정답을 구할 수 있다.
* 
* 삼중 for 문이 어떻게 설정되어있는지를 유심히 확인하길 바란다.
* 또한 바킹독님의 해설을 참고하여 풀었다. 아래는 내가 참고한 바킹독님의 블로그 링크이다.
* https://blog.encrypted.gg/418
* 
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int mx = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		dp[i][i] = arr[i];
		mx = max(dp[i][i], mx);
	}
	for (int sep = 1; sep < n; ++sep) {
		for (int i = 1; i <= n - sep; ++i) {
			for (int j = i; j < i + sep; ++j) {
				if (dp[i][j] != 0 && dp[i][j] == dp[j + 1][i + sep]) {
					dp[i][i + sep] = max(dp[i][j] + 1, dp[i][i + sep]);
					mx = max(mx, dp[i][i + sep]);
				}
			}
		}
	}
	cout << mx;
}
