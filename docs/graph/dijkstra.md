# 다익스트라 알고리즘

다익스트라 알고리즘은 O(V^3)인 플로이드 와샬보다 O((V+E)logV)으로    
속도면에서 그리고 모든 점들과의 경로를 구할 때 효율적으로 값을 구할 수 있다는 점에서 유용하다.

대표적으로 처음 배우는 그래프의 최단 경로 알고리즘으로,  
**특정 정점에서 다른 *모든* 정점으로 가는 최단 경로를 구해준다.**

각각의 정점에서 정점으로 가는 최단경로값의 배열을 만든 뒤,
N에서 1부터 N까지 가는 모든 최단 경로의 최솟값을 계속 구해나가면서 각각의 정점으로부터 최단경로값을 구하는 방식이다.

코드로 보자.

```cpp
vector<pair<int, int>> graph[1001];

int dijkstra(int from, int to){
    priority_queue<pair<int, int>> pq;
    
    pq.push(make_pair(0, from));

    dp[from][from] = 0; // 자기 자신은 오도가도 할 이유가 없으므로 0

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first; // min heap으로 활용한다.
        pq.pop();

        //찾아볼 이유가 없는 비효율 적인 경우 패스
        if(cost > dp[from][here] && dp[from][here] != -1) continue;
        
        // 인접 노드 중 효율적인 노드가 보일 경우를 찾는다.
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
```