#include<iostream>
#include<string>
using namespace std;

const int dir[4][3][2] = {
    {{0,0},{0,1},{1,0}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};

int cover_board(int y, int x, int** board){
	bool finish = true;
	for(int i = 0; i<y; ++i)
	    for(int j = 0; j<x; ++j)
	        if(board[i][j] == 0) finish = false;
	int ret = 0;
    int curx = -1, cury = -1;
	if(finish) return 1;
	for(int i = 0; i<y; ++i){
	    for(int j = 0; j<x; ++j)
            if(board[i][j] == 0){
                curx = j;
                cury = i;
                break;
            }
        if(cury != -1) break;
    }
    // if found most left & top block, start placing.
    for(int i = 0; i<4; ++i){
        bool canPlace = true;
        int nextX, nextY;
        for(int j = 0; j<3; ++j){
            nextY = cury + dir[i][j][0];
            nextX = curx + dir[i][j][1];
            if(0 > nextY || nextY >= y || 0 > nextX || nextX >= x)
                canPlace = false;
            else if(board[nextY][nextX] == 1) canPlace = false;
        }
        for(int j = 0; j < 3 && canPlace; ++j){
            nextY = cury + dir[i][j][0];
            nextX = curx + dir[i][j][1];
            board[nextY][nextX] = 1;
        }
        if(canPlace) ret += cover_board(y, x, board);
        // assertion
        for(int j = 0; j < 3 && canPlace; ++j){
            nextY = cury + dir[i][j][0];
            nextX = curx + dir[i][j][1];
            board[nextY][nextX] = 0;
        }
    }
	return ret;
}

int main(){
	int t; cin>>t;
	while(t--){
        int Ax, Ay;
		string lineInput;
		cin >> Ay >> Ax;
		int** board = new int*[Ay];
        bool allBlocked = true;
		for(int i = 0; i<Ay; ++i)
			board[i] = new int[Ax];
		for(int i = 0; i<Ay; ++i){
			cin>>lineInput;
			for(int j = 0; j<Ax; ++j){
				if(lineInput[j] == '#')
					board[i][j] = 1;
				else if(lineInput[j] == '.'){
					board[i][j] = 0;
                    allBlocked = false;
                }
			}
		}
        if(allBlocked) cout<<0<<'\n';
        else cout<<cover_board(Ay, Ax, board)<<'\n';
		for(int i = 0; i<Ay; ++i)
			delete[] board[i];
		delete[] board;
	}
}
