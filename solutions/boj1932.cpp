#include<iostream>
using namespace std;

//cache value : maximum sum value from the position to below.
int cache[500][500];
int triangle[500][500];

int solve(int N, int cury, int curx){
    if(cury == N - 1){
        return cache[cury][curx] = triangle[cury][curx];
    }

    if(cache[cury][curx] != -1) return cache[cury][curx];
    
    // get answer that is maximum value.
    int tmp1 = triangle[cury][curx] + solve(N, cury+1, curx);
    int tmp2 = triangle[cury][curx] + solve(N, cury+1, curx+1);

    return cache[cury][curx] = tmp1 < tmp2 ? tmp2 : tmp1;
}

int main(){
    int N; cin>>N;
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<i+1; ++j){
            cin>>triangle[i][j];
            cache[i][j] = -1;
        }
    }
    cout<<solve(N, 0, 0);
    return 0;
}
