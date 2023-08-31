#include<iostream>
#include<vector>
using namespace std;

bool visit[1001];
vector<int> graph[1001];

void dfs(int node){
    visit[node] = true;
    for(int child : graph[node]){
        if(!visit[child]) dfs(child);
    }
}

int component(int N){
    int counts = 0;
    for(int i = 1; i<=N; ++i){
        if(!visit[i]){
            dfs(i);
            counts++;
        }
    }
    return counts;
}

int main(){
    int N, M; cin>>N>>M;
    for(int i = 0; i<M; ++i){
        int a1, a2; cin>>a1>>a2;
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
    }
    cout<<component(N);
}