#include<iostream>
#include<cstring>
using namespace std;

const int BOARD_SIZE = 9;
int board[BOARD_SIZE][BOARD_SIZE];
bool row[9][10]; // i행에 j가 사용됐는가?
bool col[9][10]; // i열에 j가 사용됐는가?
bool box[9][10]; // i번째 작은칸에 j가 사용됐는가?

void solve(int idx){
    if(idx == BOARD_SIZE*BOARD_SIZE){ // 81 = over the index
        for(int i=0; i<BOARD_SIZE; ++i){
            for(int j=0; j<BOARD_SIZE; ++j){
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
        exit(0);
    }
    int x = idx%9;
    int y = idx/9;
    int block = (y/3)*3 + x/3;
    if(board[y][x]) solve(idx + 1);
    else{
        for(int i=1; i<=BOARD_SIZE; ++i){
            if(!row[y][i] && !col[x][i] && !box[block][i]){
                row[y][i] = col[x][i] = box[block][i] = true;
                board[y][x] = i;
                solve(idx + 1);
                board[y][x] = 0;
                row[y][i] = col[x][i] = box[block][i] = false;
            }
        }
    }
}

int main(){
    for(int i=0; i<BOARD_SIZE; ++i){
        for(int j=0; j<BOARD_SIZE; ++j){
            cin>>board[i][j];
            if(board[i][j]){
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                box[(i/3)*3+j/3][board[i][j]] = true;
            }
        }
    }
    solve(0);
}