#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, long long>> graph[5001];
long long mx;
bool visited[5001];

void dfs(int node, long long score) {
    // 문제 조건에 의해 모든 지점은 단 한번씩만 방문.
    visited[node] = true;
    if (score > mx) {
        mx = score;
    }
    for (pair<int, int> i : graph[node]) {
        if (node == i.first || visited[i.first])
            continue; // 온쪽은 무시
        dfs(i.first, score + i.second);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int s, e, c;
        cin >> s >> e >> c;
        s--;
        e--;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }
    dfs(0, 0);
    cout << mx;
}