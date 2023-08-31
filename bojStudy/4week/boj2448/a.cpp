#include<iostream>
using namespace std;

bool map[3072][6144];

void solve(int K, int startX, int startY){
    if(K == 3){
        map[startY][startX + 2] = map[startY + 1][startX + 1] = map[startY + 1][startX + 3] = true;
        for(int i=0; i<5; ++i) map[startY + 2][startX + i] = true;
        return;
    }
    solve(K/2, startX + K/2, startY);
    solve(K/2, startX, startY + K/2);
    solve(K/2, startX + K, startY + K/2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int N; cin>>N;
    solve(N, 0, 0);
    for(int i=0; i<N; ++i){
        for(int j=0; j<2*N; ++j){
            if(map[i][j]) cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
}