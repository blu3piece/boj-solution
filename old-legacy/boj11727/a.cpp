#include<iostream>
using namespace std;

int cache[1001];

int solve(int N){
    if(N < 1) return 0;
    if(cache[N] != 0) return cache[N];
    if(N == 1){
        return 1;
    }
    if(N == 2){
        return 3;
    }
    cache[N] = 2*solve(N-2) + solve(N-1);
    cache[N] %= 10007;
    return cache[N];
}

int main(){
    int N; cin>>N;
    cout<<solve(N);
    return 0;
}