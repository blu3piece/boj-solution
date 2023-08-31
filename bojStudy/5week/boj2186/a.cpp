#include<iostream>
#include<cstring>
using namespace std;

char mat[100][100];
int DP[100][100][81];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M, K;

int charMatrix(int y, int x, string word, int count){
    if(DP[y][x][count] != -1) return DP[y][x][count];
    if(count == word.length()) return 1;
    int ans = 0;

    for(int i = 1; i<=K; ++i){

        for(int l=0; l<4; ++l){

            int offsetX = x + i*dir[l][1];
            int offsetY = y + i*dir[l][0];

            if(0 <= offsetY && offsetY < N){

                if(0 <= offsetX && offsetX < M){

                    if(mat[offsetY][offsetX] == word[count]){

                        DP[offsetY][offsetX][count + 1] = charMatrix(offsetY, offsetX, word, count + 1);
                        ans += DP[offsetY][offsetX][count + 1];
                    }
                }
            }
        }
    }
    DP[y][x][count] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(DP, -1, sizeof(DP));
    cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        string input; cin>>input;
        for(int j=0; j<M; ++j) mat[i][j] = input[j];
    }
    string word; cin>>word;
    int count = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(mat[i][j] == word[0]){
                count += charMatrix(i, j, word, 1);
            }
        }
    }
    cout<<count;
}