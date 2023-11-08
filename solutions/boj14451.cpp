/**
 * n이 20밖에 안되니 배열에 쌩으로 모든 경우를 저장할 수가 있다.
 * 비트필드를 이용한 dp 에서 위와같은 방식을 활용한다.
 * 다차원 배열을 통해 board에서도 모든 경우의 수 활용을 할 수 있다.
 * queue에 각각의 상태를 저장하기 보단, 배열에 각각의 상태를 이런식으로 저장할 수 있다는 점을
 * 생각을 하지 못한 것 같다.
 * visit 대신 dp를 활용할 수 있음을 생각해봐야할 것 같다.
 *
 * 이 방식을 이용하면, 위치가 기준이 아닌, 방향과 위치를 기준으로 잡았기 때문에, 좌회전, 우회전, 전진 만 해주면 된다.
 * 위를 기준으로 하게 되면 중복되는 경우의 수도 모두 잡을 수 있고 bfs이기 때문에 최적화까지 자연스레 잡힌다.
 *
 * 나에겐 이정도 수준은 구상도 활용도 아직 쉽지가 않다.
 * 추후에 문제를 다시 풀어봐야할 것 같다.
*/

#include<iostream>
#include<queue>
using namespace std;

int n;
int dp[21][21][4][21][21][4];
int board[21][21];

typedef struct State {
	int y_1;
	int x_1;
	int d_1;
	int y_2;
	int x_2;
	int d_2;
} State;

queue<State> q;

const int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	string buf;
	for (int i = 0; i < n; ++i) {
		cin >> buf;
		for (int j = 0; j < n; ++j) {
			if (buf[j] == 'H') board[i][j] = 1;
		}
	}

	dp[n - 1][0][0][n - 1][0][1] = 0;
	q.push({ n - 1, 0, 0, n - 1, 0, 1 });

	while (!q.empty()) {
		State t = q.front(); q.pop();
		int len = dp[t.y_1][t.x_1][t.d_1][t.y_2][t.x_2][t.d_2];
		if (t.y_1 == 0 && t.y_2 == 0 && t.x_1 == n - 1 && t.x_2 == n - 1) {
			cout << dp[t.y_1][t.x_1][t.d_1][t.y_2][t.x_2][t.d_2];
			break;
		}

		State right = t; // 우회전하기
		State left = t; // 좌회전하기
		State advance = t; // 전진하기

		right.d_1 = (right.d_1 + 1) % 4;
		right.d_2 = (right.d_2 + 1) % 4;

		if (!dp[right.y_1][right.x_1][right.d_1][right.y_2][right.x_2][right.d_2]) {
			dp[right.y_1][right.x_1][right.d_1][right.y_2][right.x_2][right.d_2] = len + 1;
			q.push(right);
		}

		left.d_1 = left.d_1 - 1 < 0 ? 3 : left.d_1 - 1;
		left.d_2 = left.d_2 - 1 < 0 ? 3 : left.d_2 - 1;

		if (!dp[left.y_1][left.x_1][left.d_1][left.y_2][left.x_2][left.d_2]) {
			dp[left.y_1][left.x_1][left.d_1][left.y_2][left.x_2][left.d_2] = len + 1;
			q.push(left);
		}
	
		if (advance.y_1 != 0 || advance.x_1 != n - 1) {
			int dy1 = advance.y_1 + dir[advance.d_1][0];
			int dx1 = advance.x_1 + dir[advance.d_1][1];
			if (dy1 < n && dy1 >= 0 && dx1 < n && dx1 >= 0 && !board[dy1][dx1]) {
				advance.y_1 = dy1;
				advance.x_1 = dx1;
			}
		}

		if (advance.y_2 != 0 || advance.x_2 != n - 1) {
			int dy2 = advance.y_2 + dir[advance.d_2][0];
			int dx2 = advance.x_2 + dir[advance.d_2][1];
			if (dy2 < n && dy2 >= 0 && dx2 < n && dx2 >= 0 && !board[dy2][dx2]) {
				advance.y_2 = dy2;
				advance.x_2 = dx2;
			}
		}

		if (!dp[advance.y_1][advance.x_1][advance.d_1][advance.y_2][advance.x_2][advance.d_2]) {
			dp[advance.y_1][advance.x_1][advance.d_1][advance.y_2][advance.x_2][advance.d_2] = len + 1;
			q.push(advance);
		}
		
	}
}