#include<iostream>
#include<utility>
#include<vector>
using namespace std;

typedef pair<int, int> pii;

int w, h, g, e;

int dir[4][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

/*

https://boj.kr/3860

벨만 포드 문제였다.
처음엔 감이 안잡혔는데, 음수 사이클이라는 말을 보고 벨만포드가 아닌가 생각했다.

솔직히 플레5 문제인데 난이도 모르고 봤을 땐 접근하기 쉬웠다. 플레문제에 조금씩 다가서는게 느껴져서 좋았다.

다만 여기서 조금 헤맸던 점이 몇개 있는데,

1. 음수사이클과 impossible 의 우선순위
2. 도착점을 처리하는 과정

1 번에 대해서는 문제의 설명이 조금 부족하지 않았나 싶은게,
도착할 수 없는 경우나 음수 사이클이 존재하는 경우나 다 똑같은 경우가 아닌가? 싶었다.
결국 도착점이 갱신되는 경우만 체크하면 되는줄 알았는데, 오히려 그냥 음수사이클이 존재하는지만 알면된다.

음수사이클이 존재하기만 하면 그걸 이용해서 결국엔 도착점까지 가는데에 시간 단축이 무한으로 이루어진다는걸 알 수 있기 때문.

2번에 대해서는 내가 확실히 좀 부족했다.
1번과 이어지는 내용이라고 생각하는데, 도착점에 도착하자마자 더이상 다른 곳으로 갈 이유가 없다는 것을 생각하지 못했다.

벨만포드 알고리즘을 사용하니까, 해당 도착점이 출발점이 될 필요는 결코 없는 것이였다.
최적화는 도착점으로 가는 출발노드에서 갱신이 되기 때문이다.

*/


int main() {
	cout.tie(0); cin.tie(0)->sync_with_stdio(0);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<vector<int>> board(h, vector<int>(w, 0));
		vector<vector<int>> time(h, vector<int>(w, -1));
		vector<vector<bool>> visit(h, vector<bool>(w, false));
		vector<pair<int, pii>> edges; // { cost , { u , v } }

		cin >> g;
		for (int i = 0; i < g; ++i) {
			int x, y; cin >> x >> y;
			board[y][x] = -1; // 묘비
		}

		cin >> e;
		int idx = 0;
		for (int i = 0; i < e; ++i) {
			int x1, y1, x2, y2, c; cin >> x1 >> y1 >> x2 >> y2 >> c;
			board[y1][x1] = 1;
			edges.push_back({ c, { y1 * w + x1, y2 * w + x2 } });
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (!board[i][j]) {
					if (i == h - 1 && j == w - 1) continue;
					for (int k = 0; k < 4; ++k) {
						int di = i + dir[k][0]; int dj = j + dir[k][1];
						if (di >= h || di < 0 || dj >= w || dj < 0) continue;
						if (board[di][dj] == -1) continue;
						edges.push_back({ 1, {i * w + j, di * w + dj} });
					}
				}
			}
		}
		
		time[0][0] = 0;
		visit[0][0] = true;
		bool infinite = false;

		for (int i = 0; i <= h * w - g; ++i) { // node 개수만큼 충분히 수행
			for (pair<int, pii> t : edges) {
				int cost = t.first;
				int fromY = t.second.first / w; int fromX = t.second.first % w;
				int toY = t.second.second / w; int toX = t.second.second % w;

				if (!visit[fromY][fromX]) continue;

				if (!visit[toY][toX] || time[toY][toX] > cost + time[fromY][fromX]) {
					if (i == h * w - g) {
						infinite = true;
					}
					visit[toY][toX] = true;
					time[toY][toX] = cost + time[fromY][fromX];
				}
			}
		}

		if (infinite) {
			cout << "Never\n";
		}

		else if (!visit[h - 1][w - 1]) {
			cout << "Impossible\n";
		}
		else cout << time[h - 1][w - 1] << '\n';
	}
}