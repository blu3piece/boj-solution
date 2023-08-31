#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, string> pis;

bool visit[10000];

string solve(int from, int to){
    memset(visit, false, sizeof(visit));
    queue<pis> q;
    q.push(make_pair(from, ""));
    visit[from] = true;
    while(!q.empty()){
        pis node = q.front(); q.pop();
        if(node.first == to) return node.second;
        
        int tmp = node.first*2%10000;
        if(!visit[tmp]){
            visit[tmp] = true;
            q.push(make_pair(tmp, node.second + "D"));
        }
        
        tmp = node.first - 1 != -1 ? node.first - 1 : 9999;
        if(!visit[tmp]){
            visit[tmp] = true;
            q.push(make_pair(tmp, node.second + "S"));
        }
        
        tmp = node.first/1000 + (node.first*10)%10000;
        if(!visit[tmp]){
            visit[tmp] = true;
            q.push(make_pair(tmp, node.second + "L"));
        }

        tmp = (node.first%10)*1000 + node.first/10;
        if(!visit[tmp]){
            visit[tmp] = true;
            q.push(make_pair(tmp, node.second + "R"));
        }
    }
    return "";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin>>T;
    while(T--){
        int from, to; cin>>from>>to;
        cout<<solve(from, to)<<'\n';
    }
}