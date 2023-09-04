#include<iostream>
using namespace std;

int cache[201][201];

int solve(int N, int K){
    if(cache[N][K]) return cache[N][K];
    if(K == 1){
        return 1;
    }
    int ans = 0;
    for(int i = 0; i<=N; ++i){
        ans += solve(N - i, K - 1);
        ans %=1000000000;
    }
    return cache[N][K] = ans;
}

int main(){
    int N, K; cin >> N >> K;
    cout<<solve(N, K);
    return 0;
}
