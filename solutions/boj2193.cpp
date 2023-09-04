#include<iostream>
using namespace std;

long long cache[91];

long long solve(int N){
    if(cache[N]) return cache[N];
    cache[N] = solve(N - 1) + solve(N - 2);
    return cache[N];
}

int main(){
    int N; cin>>N;
    cache[1] = 1;
    cache[2] = 1;
    long long ans = solve(N);
    cout<<ans;
}