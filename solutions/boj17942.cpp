/*
* 깨닫는데 1시간 걸렸따...

비용이 커지면 자연스레 해당 비용보다 적은 비용을 들이는 문제는 모두 풀 수 있게 된다.
이점을 활용하여 pq에 경우의 수가 남아 있어도 그리디 알고리즘에 의해서 문제를 풀 수 있게 된다.

따라서, { (최저)비용 , (최대)해결 알고 개수 } 로 문제를 둔다.

0. pq에 주어진대로 해당 { 17, 1 } 와 같이 넣는다.

1. 문제 pq를 둔다. { 요구 비용, 번호 }

탑 문제가 이미 해결됐다면 버린다(continue)

탑 문제가 요구 비용보다 낮거나 안올려도 되고, 높으면 해당 비용만큼 현재 비용을 올리고, m의 개수를 갱신(++)한다.

특정 문제가 해결되면 나머지 해결된 모든 노드를 pq에 넣는다. (예를들어, 1을 현재 보고 있따면, pq에 (17, 3) 을 넣는다.

*/

#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<pii> pq;
	int n, m, r; cin >> n >> m;
	vector<int> arr(n + 1);
	vector<vector<pii>> adj(n + 1, vector<pii>(0));
	vector<bool> visit(n + 1, false);
	int cost = 0;
	int cnt = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		pq.push({ -arr[i], i});
	}
	cin >> r;
	for (int i = 0; i < r; ++i) {
		int a, b, d; cin >> a >> b >> d;
		adj[a].push_back({ b, d });
	}

	while (!pq.empty() && cnt < m) {
		int node = pq.top().second;
		int value = -pq.top().first; pq.pop();
		if (visit[node]) continue;
		if (cost < value) cost = value;
		cnt++;
		visit[node] = true;

		for (pii t : adj[node]) {
			int next_node = t.first;
			int next_cost = arr[t.first] - t.second;

			if (next_cost < 0) next_cost = 0;
			arr[next_node] = next_cost;

			pq.push({ -next_cost, next_node });
		}
	}

	cout << cost;
}