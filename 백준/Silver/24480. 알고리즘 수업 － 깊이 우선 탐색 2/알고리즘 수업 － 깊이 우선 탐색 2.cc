#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visited[100001];
vector<int> graph[100001];
int idx = 1;
int N, M, R;

void dfs(int node) {
    sort(graph[node].begin(), graph[node].end(), greater<int>());
    for (int i : graph[node]) {
        if(!visited[i]) {
            visited[i] = ++idx;
            dfs(i);
        }
    }
}

int main() {
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>R;
    for(int i=0; i<M; ++i) {
        int s, e;
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    visited[R] = idx;
    
    dfs(R);

    for(int i=1; i<=N; ++i) {
        cout<<visited[i]<<'\n';
    }
}