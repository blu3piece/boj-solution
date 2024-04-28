/**
 * if(s || (!dp[i] || dp[i] > score)) 이라고 조건분기를 써서 틀렸다.
 * 
 * 무지성 BFS 금지..
*/

#include<iostream>
#include<queue>
using namespace std;

int something[101]; // 뱀이나 사다리
int dp[101]; // 현재 여기까지 온 최단 거리

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n+m; ++i) {
        int from, to;
        cin>>from>>to;
        something[from] = to;
    }
    
    queue<int> q;

    dp[1] = 1;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        
        q.pop();
        int score = dp[cur] + 1;

        for(int i=cur+1; i<=cur+6; ++i) {
            if(i > 100) continue;

            int s = something[i];

            if(s) {
                if(!dp[s] || dp[s] > score) {
                    dp[s] = score;
                    q.push(s);
                }
                
            }
            else {
                if(!dp[i] || dp[i] > score) {
                    dp[i] = score;
                    q.push(i);
                }
            }
        }
    }
    cout<<dp[100] - 1;
}