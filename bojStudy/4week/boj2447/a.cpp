#include<iostream>
using namespace std;

bool map[6561][6561];

void star(int N, int startX, int startY){
    if(N == 3){
        for(int i = startY; i<startY + N; ++i){
            for(int j=startX; j<startX + N; ++j){
                if(i == startY + 1 && j == startX + 1) map[i][j] = false;
                else map[i][j] = true;
            }
        }
        return;
    }
    for(int i = startY; i<startY + N; i += N/3){
        for(int j=startX; j<startX + N; j += N/3){
            if(!(i == startY + N/3 && j == startX + N/3)) star(N/3, j, i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int N; cin>>N;
    star(N, 0, 0);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(!map[i][j]){
                cout<<' ';
            }
            else cout<<'*';
        }
        cout<<'\n';
    }
}