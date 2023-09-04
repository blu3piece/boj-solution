#include<iostream>
using namespace std;

int cache[1001][10];

int solve(int N, int digit){
    if(cache[N][digit]) return cache[N][digit];
    if(N == 1 && digit){
        return cache[1][digit];
    }
    int ans = 0;
    for(int i = 9; i>=digit; --i){
        ans += solve(N - 1, i);
        ans %= 10007;
    }
    cache[N][digit] = ans;
    return ans;
}

int main(){
    int N; cin>>N;
    int ans = 0;
    for(int i = 0; i<10; ++i) cache[1][i] = 1;
    for(int i = 0; i<10; ++i){
        ans += solve(N, i);
        ans %= 10007;
    }
    cout<<ans;
    return 0;
}