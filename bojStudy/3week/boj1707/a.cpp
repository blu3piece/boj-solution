#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> adj[20001];
bool visit[2001];

void dfs(int node, int N){
    visit[node] = true;
    for(int child : adj[node]){
        if(!visit[child]) dfs(child, N);
    }
}

bool isBinaryGraph(int N){
    memset(visit, false, sizeof(visit));
    int inOne = 0;
    int notInOne = 0;
    dfs(1, N);
    for(int i = 1; i<=N; ++i){
        if(visit[i]) inOne++;
        else if(!notInOne) notInOne = i;
    }
    
    if(!notInOne) return false;

    dfs(notInOne, N);

    for(int i = 1; i<=N; ++i){
        if(!visit[i]) return false;
    }
    return true;
}

int main(){
    int K; cin>>K;
    while(K--){
        int V, E; cin>>V>>E;
        for(int i = 0; i<E; ++i){
            int a1, a2; cin>>a1>>a2;
            adj[a1].push_back(a2); adj[a2].push_back(a1);
        }
        cout<<(isBinaryGraph(V) ? "YES" : "NO")<<'\n';
        for(int i = 1; i<=V; ++i) adj[i].clear();
    }
}