#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int gem[101]; // 0 : 보석 없음 / 1 ~ : n번째 보석.
bool dp[101][20001]; // 챙긴 보석의 상태, 현재 위치
vector<pii> graph[101];

int main(){
    int n, m, k; cin>>n>>m>>k;
    for(int i=1; i<=k; ++i) {
        int t; cin>>t;
        gem[t] = i;
    }

    for(int i=0; i<m; ++i) {
        int s, e, c; cin>>s>>e>>c;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }

    queue<pii> q;
    
    q.push({1, 0}); // (현재 위치, 챙긴 보석 상태(비트마스킹) )
    dp[1][0] = true; // 현재 아무것도 안챙긴 상태 (무게와 동일)

    while(!q.empty()) {
        int place = q.front().first;
        int g = q.front().second; // 현재 든 보석 상태
        int weight = 0;

        for(int i=0; i<k; ++i) {
            if((1 << i) & g) {
                weight++;
            }
        }

        q.pop();
        
        for(pii node : graph[place]) {
            if(weight <= node.second) {
                // 다리가 안무너지는 경우

                if(gem[node.first]) {
                    // 다음에 가는 곳에 보석이 있는 경우.
                    if (!(g & (1 << (gem[node.first] - 1)))) {
                        // 이미 챙긴 보석이 아닌 경우
                        // 가고 나서 거기서 챙기기
                        int next_g = g | (1 << (gem[node.first] - 1));
                        if(!dp[node.first][next_g]) {
                            q.push({node.first, next_g});
                            dp[node.first][next_g] = true;
                        }
                    }
                }
                
                // 보석을 안챙기고 그냥 이동.
                if(dp[node.first][g]) continue; // 의미없는 경우.
                dp[node.first][g] = true;
                q.push({node.first, g});
            }
            
        }

    }
    int mx = 0;
    for(int i=0; i<20000; ++i) {
        if(!dp[1][i]) continue;
        int weight = 0;
        for(int j=0; j<k; ++j) {
            if((1 << j) & i) {
                weight++;
            }
        }
        
        mx = mx < weight ? weight : mx;
    }
    cout<<mx;
}