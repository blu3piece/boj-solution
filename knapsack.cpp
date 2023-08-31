#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[100001]; // i 개의 작은 순의 코인으로 만들 수 있는 j 수
int temp[100001];
int coins[100];

// 조합 이론 중 하나인 배낭문제에 대해서 공부해보자.

// int getCase(int n, int k) {
//     if(k == 0) return 1;
//     if(k < 0 || n < 0) return 0;ㅁ
//     if(dp[n][k] > -1) return dp[n][k];
//     int temp = k;
//     dp[n][k] = getCase(n-1, temp);
//     while(temp >= coins[n]){
//         temp -= coins[n];
//         dp[n][k] += getCase(n-1, temp);
//     }
//     return dp[n][k];
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K; cin>>N>>K;

    for(int i=0; i<N; ++i) cin>>coins[i];
    sort(coins, coins+N);
    dp[0] = 1;
    for(int n=0; n<N; ++n) {
        for(int k=0; k<=K; ++k) {

            if(k == 0) {
                temp[k] = 1;
                continue;
            }

            int temp_k = k;

            while(temp_k >= coins[n]) {
                temp_k -= coins[n];
                temp[k] += dp[temp_k];
            }
        }
        memcpy(dp, temp, sizeof(dp));
    }
    cout<<dp[K];
}