#include<iostream>
#include<queue>
using namespace std;

int n, m;
int graph[1001][1001];
bool visited[1001][1001];
int dist[1001][1001];

queue<pair<int, int>> q;

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    int sX, sY;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>graph[i][j];
            if(graph[i][j] == 2) {
                sX = j;
                sY = i;
            }
            if(graph[i][j] == 1) {
                dist[i][j] = -1;
            }
        }
    }
    q.push({sY, sX});
    visited[sY][sX] = true;
    while(!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int scr = dist[y][x];
        
        for(int i=0; i<4; ++i) {
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            if(dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
            if(!graph[dy][dx]) continue;
            if(visited[dy][dx]) continue;
            dist[dy][dx] = scr+1;
            visited[dy][dx] = true;
            q.push({dy, dx});
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
}