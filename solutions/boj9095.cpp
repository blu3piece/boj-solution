#include<iostream>
using namespace std;

int cache[12] = { 0, 1, 2, 4, };

int solve(int N){
    if(cache[N] == 0) cache[N] = solve(N-1) + solve(N-2) + solve(N-3);
    return cache[N];
}

int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        cout<<solve(N)<<'\n';
    }
}