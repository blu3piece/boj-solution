#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
bool visit[100001];

int find(int N, int K){
    queue<pii> q;
    q.push(make_pair(N, 0));
    while(!q.empty()){
        pii node = q.front(); q.pop();
        visit[node.first] = true;
        if(node.first == K) return node.second;
        if(node.first*2 <= 100000 && !visit[node.first*2]) q.push(make_pair(node.first*2, node.second + 1));
        if(node.first + 1 <= 100000 && !visit[node.first + 1]) q.push(make_pair(node.first + 1, node.second + 1));
        if(node.first - 1 >= 0 && !visit[node.first - 1]) q.push(make_pair(node.first - 1, node.second + 1));
    }
    return -1;
}

int main(){
    int N, K; cin>>N>>K;
    cout<<find(N, K);
}