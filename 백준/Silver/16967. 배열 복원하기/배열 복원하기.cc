#include<iostream>
using namespace std;


int mat[1000][1000];

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int h, w, x, y; cin>>h>>w>>x>>y;
    for(int i=0; i<x + h; ++i) {
        for(int j=0; j<y + w; ++j) {
            cin>>mat[i][j];
        }
    }

    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if (i >= x && j >= y) {
                cout<<mat[i][j] - mat[i-x][j-y]<<' ';
                mat[i][j] = mat[i][j] - mat[i-x][j-y];
            }
            else {
                cout<<mat[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
}