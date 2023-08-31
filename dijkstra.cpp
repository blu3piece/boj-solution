// 백준 1238

// 백트래킹 vs bfs
// dfs 로 순회를 돌면서 자기 집으로 도착하는 시간을 구하기 (백트래킹이 아닌, 단순 dfs로 해야할듯)

// => 시간 초과 , 효율적인 한 정점으로부터 모든 정점으로의 경로계산 == 다익스트라

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<pair<int, int>> graph[1001]; // 단방향 그래프, (to, cost)

int dp[1001][1001]; // 최단경로 memoization

int dijkstra(int from, int to){
    priority_queue<pair<int, int>> pq;
    
    pq.push(make_pair(0, from));

    dp[from][from] = 0;

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost > dp[from][here] && dp[from][here] != -1) continue;
        
        for(auto t : graph[here]) {
            int there = t.first;
            int _dist = t.second + cost;
            if(dp[from][there] == -1 || _dist < dp[from][there]) {
                dp[from][there] = _dist;
                pq.push(make_pair(-_dist, there));
            }
        }
    }
    return dp[from][to];
}

// from 부터 to 까지 가는데 걸리는 최소 비용 계산
// int getTime (int from, int to) {
//     visit[from] = true;
//     if(from == to){
//         visit[from] = false;
//         return 0; // has path
//     }
//     int _min = 101; // if has no path
//     for(pair<int, int> t : graph[from]) {
//         if(!visit[t.first]) {
//             int _cost = getTime(t.first, to);
//             if(_cost > 100) continue;
//             _cost += t.second;
//             _min = _min > _cost ? _cost : _min;
//         }
//     }
//     visit[from] = false;
//     return _min;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, X; cin>>N>>M>>X;
    memset(dp, -1, sizeof(dp)); // -1 == INF

    for(int i=0; i<M; ++i) {
        int from, to, cost; cin>>from>>to>>cost;
        graph[from].push_back(make_pair(to, cost));
    }

    int max = -1;
    for(int i=1; i<=N; ++i) {
        if(i == X) continue;
        int overall_cost = dijkstra(i, X) + dijkstra(X, i);
        cout<<"overall_cost : "<<overall_cost<<endl;
        max = overall_cost > max ? overall_cost : max;
    }
    cout<<max;
    return 0;
}