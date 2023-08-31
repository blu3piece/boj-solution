#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

bool visit[1000001];
int up, down;

int getMinPress(int N, int now, int dest){
    queue<pii> q;
    visit[now] = true;
    q.push(make_pair(now, 0));
    while(!q.empty()){
        pii state = q.front(); q.pop();
        if(state.first == dest) return state.second;
        if(state.first + up <= N && !visit[state.first + up]){
            visit[state.first + up] = true;
            q.push(make_pair(state.first + up, state.second + 1));
        }
        if(state.first - down > 0 && !visit[state.first - down]){
            visit[state.first - down] = true;
            q.push(make_pair(state.first - down, state.second + 1));
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, now, dest;
    cin>>N>>now>>dest>>up>>down;
    int ans = getMinPress(N, now, dest);
    if(ans == -1) cout<<"use the stairs";
    else cout<<ans;
}