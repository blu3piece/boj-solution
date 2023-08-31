#include<iostream>
using namespace std;

int cache[101][10];

int solve(int N, int digit){
    if(cache[N][digit]) return cache[N][digit];
    if(N == 1) return cache[N][digit];
    int ans = 0;
    if(digit > 0) ans += solve(N-1, digit-1);
    if(digit < 9) ans += solve(N-1, digit+1);
    ans %= 1000000000;
    cache[N][digit] = ans;
    return ans;
}

int main(){
    int N; cin>>N;
    for(int i = 1; i<=9; ++i) cache[1][i] = 1;
    int ans = 0;
    for(int i = 0; i<=9; ++i){
        ans += solve(N, i);
        ans %= 1000000000;
    }
    cout<<ans;
    return 0;
}