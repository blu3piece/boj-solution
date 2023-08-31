# 위상 정렬

https://m.blog.naver.com/ndb796/221236874984

## 이해 : 도대체 indegree가 뭔데?

indegree, 자신에게 들어오는 간선의 갯수를 나타내는 배열이다.

큐에 indegree가 0인, 즉 leaf 노드들을 넣어서 순회를 하는데, 각 leaf 노드를 시작점으로 하는 간선을 확인할 때, 이 leaf 노드는 순회가 끝났으므로 다음 단계에서는 해당 노드에서 시작되는 간선을 없다고 생각하고 다음 단계를 진행해도 똑같다. 이미 leaf 노드를 순회 완료했기 때문에. 그래서 이 간선들이 없어지면 노드가 가르키는 도착점의 노드들의 indegree를 지우는 것이고, indegree가 0일 경우 해당 노드의 순회조건이 완료(선행 노드들이 다 실행된 경우이다.) 되므로 큐에 넣는 방식으로 sorting 이 된다.

## 왜 빠른가?

왜 빠르지? 왜빠른지만 납득하면 해당 상황에서 이거만 쓸거같긴함 ㅇㅇ

1. 일단 큐를 이용해서 모든 노드를 한번씩만 수행함. 즉, 큐 반복문이 실행되는 횟수는 V 임

2. 그리고 각 V 별로 모든 간선에서 반복문을 또 수행함. 그래서 O(V + E) 가 되는데..

여기서 문제는 task 순서의 메모이제이션같은 경우, dfs 같은 경우는 모든 node에서 일일이 출발해야한다. dfs의 경우 최악일경우 O(V + E)인데, 같은 문제를 위상정렬은 O(V+E) 에서 정리될 수 있는데 dfs의 경우는 dfs 한번에 정리되지 않는다. 출발점이 매번 다 다르게 해야하기 때문에.. 그래서 위상정렬을 쓰는거다. 시간복잡도 자체의 경우 빠르진 않지만, 특수한 경우 dfs, bfs 같은 단순 순회보다는 훨씬 빠르다는 점을 생각하면 좋을 것 같다.

## 에제1 : [ACM Craft](https://boj.kr/1005)
```cpp
#include<bits/stdc++.h>
using namespace std;

int delay[1001];
int dp[1001];
vector<int> graph[1001];
int indegree[1001]; // 이거를  1씩 줄여나가면서 0일 경우에 해당 노드의 건설조건이 만족된다.
// 즉 indegree가 0이 되는 시점이야말로 진짜 해당 건물이 건설될 수 있는 시점을 의미한다.

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t; cin>>t;

  while(t--) {
    int N, K; cin>>N>>K;
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=N; ++i) {
      graph[i].clear();
      cin>>delay[i];
    }

    for(int i=0; i<K; ++i) {
      int t1, t2; cin>>t1>>t2;
      graph[t1].push_back(t2);
      indegree[t2]++; 
    }
    
    int W; cin>>W;
    
    queue<int> q;

    for(int i=1; i<=N; ++i) {
      if(!indegree[i]) {
        q.push(i);
        dp[i] = delay[i];
      }
    }
    
    while(!q.empty()) {
      int now = q.front();
      q.pop();

      for(int t : graph[now]) {
        if(dp[t] < dp[now] + delay[t]) dp[t] = dp[now] + delay[t];
        if(--indegree[t] == 0) q.push(t);
      }
      
    }
    cout<<dp[W]<<'\n';
  }
}
```

## 예제2 : 게임