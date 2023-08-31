#include<iostream>
using namespace std;

pair<long long, long long> count(int N){
    long long count_2 = 0, count_5 = 0;
    for(long long i = 2; i<=N; i *= 2) count_2 += N/i;
    for(long long i = 5; i<=N; i *= 5) count_5 += N/i;
    return pair<long long, long long>(count_2, count_5);
}

int main(){
    int N, M; cin>>N>>M;
    pair<long long, long long> m = count(M);
    pair<long long, long long> n = count(N);
    pair<long long, long long> minus = count(N - M);
    n.first -= (m.first + minus.first);
    n.second -= (m.second + minus.second);
    cout<<(n.first < n.second ? n.first : n.second);
}