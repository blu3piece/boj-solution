#include<iostream>
using namespace std;

bool map[64][64];

void solve(int size, int startX, int startY){
    int endX = startX + size;
    int endY = startY + size;
    if(size == 1){
        cout<<(int)map[startY][startX];
        return;
    }
    bool mono = true;
    for(int i=startY; i<endY; ++i){
        for(int j=startX; j<endX; ++j){
            if(map[startY][startX] != map[i][j]) mono = false;
        }
    }
    if(!mono){
        cout<<'(';
        solve(size/2, startX, startY);
        solve(size/2, startX + size/2, startY);
        solve(size/2, startX, startY + size/2);
        solve(size/2, startX + size/2, startY + size/2);
        cout<<')';
        return;
    }
    cout<<map[startY][startX];
}

int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string tmp; cin>>tmp;
        for(int j=0; j<N; ++j) map[i][j] = (int)tmp[j] - 48;
    }
    solve(N, 0, 0);
}