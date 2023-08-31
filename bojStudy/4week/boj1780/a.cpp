#include<iostream>
using namespace std;

int arr[2187][2187];
int ans[3]; // -1 0 1

void solve(int size, int startX, int startY, int endX, int endY){
    int init = arr[startY][startX];
    bool mono = true;
    for(int i=startY; i<endY; ++i)
        for(int j=startX; j<endX; ++j){
            if(init != arr[i][j]) mono = false;
        }
    if(mono || size == 1){
        ans[init + 1]++;
        return;
    }
    if(!mono) {
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j) solve(size/3, startX + j*size/3, startY + i*size/3, startX + (j+1)*size/3, startY + (i+1)*size/3);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i)
       for(int j=0; j<N; ++j) cin>>arr[i][j];
    solve(N, 0, 0, N, N);
    for(int i=0; i<3; ++i) cout<<ans[i]<<'\n';
}