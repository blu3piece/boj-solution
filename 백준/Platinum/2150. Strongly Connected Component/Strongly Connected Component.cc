#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int v, e;

int id[10001]; // 고유 방문 id
bool visit[10001]; // scc로 성립되어 더이상 방문할 이유가 없는 경우 확인
int id_val;
vector<int> adj[10001];
stack<int> st;

int scc_num;
int scc[10001];
bool scc_visit[10001];

int dfs_tarjan(int now) {
	id[now] = ++id_val; // 방문순서
	st.push(now);

	int result = id[now];
	
	for (int t : adj[now]) {
		if (id[t] == 0) {
			result = min(result, dfs_tarjan(t)); // 이후에 자식노드들에게서 일찍 방문했던 점(사이클의 시작점)을 찾는 과정임.
		}
		else if (!visit[t]) {
			result = min(result, id[t]); // 해당 정점이 방문했더라도, 이전에 방문한 점인지 확인.
		}
	}

	if (result == id[now]) {
		scc_num++;
		while (1) {
			int top = st.top(); st.pop();
			scc[top] = scc_num;
			visit[top] = true;

			if (top == now) break;
		}
	}
	return result;
}

int main() {
	cout.tie(0); cin.tie(0)->sync_with_stdio(0);
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int from, to; cin >> from >> to;
		adj[from].push_back(to);
	}
	for (int i = 1; i <= v; ++i) {
		if (id[i] == 0) {
			dfs_tarjan(i);
		}
	}
	cout << scc_num << '\n';
	
	for (int i = 1; i <= v; ++i) {
		if (scc_visit[i]) continue;
		int find_num = scc[i];
		for (int j = i; j <= v; ++j) {
			if (find_num == scc[j]) {
				cout << j << ' ';
				scc_visit[j] = true;
			}
		}
		cout << -1 << '\n';
	}
}