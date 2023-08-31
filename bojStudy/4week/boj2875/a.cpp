#include<iostream>
using namespace std;

int main(){
    int N, M, K; cin>>N>>M>>K;
    int total = N + M;
    int teams = 0;
    while(N >= 2 && M >= 1){
        teams++;
        N -= 2;
        M--;
    }
    while(total - teams*3 < K) teams--;
    cout<<teams;
}