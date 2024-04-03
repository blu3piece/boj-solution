#include<iostream>
using namespace std;

bool board[129][129];

int n;
int blue;
int white;

void get_part(int x, int y, int size) {
    if(size == 1) {
        if(board[y][x]) blue++;
        else white++;
        return;
    }
    bool isBlue = board[y][x];
    for(int i=y; i<y+size; ++i) {
        for(int j=x; j<x+size; ++j) {
            if(isBlue != board[i][j]) {
                get_part(x, y, size/2);
                get_part(x + size/2, y + size/2, size/2);
                get_part(x + size/2, y, size/2);
                get_part(x, y + size/2, size/2);
                return;
            }
        }
    }
    if(isBlue) {
        blue ++;
    }
    else white ++;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin>>board[i][j];
        }
    }
    get_part(0, 0, n);
    cout<<white<<'\n'<<blue;
}