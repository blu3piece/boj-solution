#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
typedef pair<int, int> pii;

int dist[801][801];
vector<pii> graph[801];

void dijkstra(int start){
    dist[start][start] = 0;
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second; // here
        pq.pop();
        if(dist[start][node] == -1 || cost > dist[start][node]) continue;
        for(auto t : graph[node]){
            int next_node = t.first;
            int _cost = t.second + cost;
            if(dist[start][next_node] == -1 || _cost < dist[start][next_node]){
                dist[start][next_node] = _cost;
                pq.push(make_pair(-_cost, next_node));
            }
        }
    }
}

int getCost(int v1, int v2, int N){
    int cost = -1;
    if(dist[1][v1] > -1 && dist[v1][v2] > -1 && dist[v2][N] > -1)
        cost = dist[1][v1] + dist[v1][v2] + dist[v2][N];
    return cost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, E, v1, v2; cin>>N>>E;
    memset(dist, -1, sizeof(dist));
    for(int i=0; i<E; ++i) {
        int tmp1, tmp2, cost; cin>>tmp1>>tmp2>>cost;
        graph[tmp1].push_back(make_pair(tmp2, cost));
        graph[tmp2].push_back(make_pair(tmp1, cost));
    }
    cin>>v1>>v2;
    dijkstra(1);
    dijkstra(v1);
    dijkstra(v2);
    int v1tov2 = getCost(v1, v2, N);
    int v2tov1 = getCost(v2, v1, N);
    if(v1tov2 < 0 && v2tov1 < 0) cout<<-1;
    else{
        v1tov2 = v1tov2 < 0 ? v2tov1+1 : v1tov2;
        v2tov1 = v2tov1 < 0 ? v1tov2+1 : v2tov1;
        cout<<(v1tov2 < v2tov1 ? v1tov2 : v2tov1);
    }
}