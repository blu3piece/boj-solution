//boj 12100
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> board;
int N;

int dir[][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

void moveBoard(int x, int y, board& bd, int d) {
    int dx = x + dir[d][0], dy = y + dir[d][1];
    if(dx < 1 || dx > N || dy < 1 || dy > N) return;
    moveBoard(dx, dy, bd, d);
    while(1) {
        if(bd[dy][dx].first == 0) {
            dy += dir[d][1];
            dx += dir[d][0];
            continue;    
        }
        if(!bd[y][x].second && !bd[dy][dx].second && bd[dy][dx].first == bd[y][x].first) {
            bd[y][x] = make_pair(0, 0);
            bd[dy][dx].first *= 2;
            bd[dy][dx].second = 1;
            return;
        }
        else if (bd[dy][dx].first != 0){
            dy -= dir[d][1];
            dx -= dir[d][0];
            bd[dy][dx] = bd[y][x];
            if(dy != y || dx != x) bd[y][x] = make_pair(0, 0);
            return;
        }
    }
}

board pushBoard(board current, int d) {
    // 0 1 2 3 (상 우 하 좌)
    // 보드를 받아 푸쉬시켜서 다시 뱉어주는 함수
    board next(current);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(next[i][j].first == 0) continue;
            moveBoard(j, i, next, d);
        }
    }
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(next[i][j].first == 0) continue;
            next[i][j].second = 0;
        }
    }
    // cout<<"board State :: \n";
    // for(int i=1; i<=N; ++i) {
    //     for(int j=1; j<=N; ++j) {
    //         cout<<next[i][j].first<<' ';
    //     }
    //     cout<<'\n';
    // }
    return next;
}

int process(int depth, board topBoard){
    int maxValue = 0;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            maxValue = maxValue < topBoard[i][j].first 
                ? topBoard[i][j].first : maxValue;

    if(depth == 5) return maxValue;

    int nextNodes[4];

    for(int i=0; i<4; ++i)
        nextNodes[i] = process(depth + 1, pushBoard(topBoard, i));
    for(int i=0; i<4; ++i)
        maxValue = maxValue < nextNodes[i] ? nextNodes[i] : maxValue;
    
    return maxValue;
}

int main(){
    cin>>N;
    board init;
    vector<pii> empty_row;
    for(int i=0; i<=N+1; ++i) {
        empty_row.push_back(make_pair(1, 1));
    }

    init.push_back(empty_row);

    for(int i=1; i<=N; ++i) {
        int tmp;
        vector<pii> row;
        row.push_back(make_pair(1, 1));
        for(int j=0; j<N; ++j) {
            cin>>tmp;
            row.push_back(make_pair(tmp, 0));
        }
        row.push_back(make_pair(1, 1));
        init.push_back(row);
    }

    init.push_back(empty_row);

    cout<<process(0, init); 
}