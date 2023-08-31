#include<iostream>
using namespace std;

int R, C;
bool visit[26];
char board[20][20];

const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


int solve(int y, int x){
    visit[board[y][x] - 65] = true;
    int ans = 1;
    int next = 0;
    for(int i=0; i<4; ++i){
        if(0 <= y + dir[i][0] && y + dir[i][0] < R &&
            0 <= x + dir[i][1] && x + dir[i][1] < C){
                if(!visit[board[y + dir[i][0]][x + dir[i][1]] - 65]){
                    int temp = solve(y + dir[i][0], x + dir[i][1]);

                    visit[board[y + dir[i][0]][x + dir[i][1]] - 65] = false;
                    
                    next = next < temp ? temp : next;
                }
            }
    }
    return ans + next;
}

int main(){
    cin>>R>>C;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin>>board[i][j];
        }
    }
    cout<<solve(0, 0);
}