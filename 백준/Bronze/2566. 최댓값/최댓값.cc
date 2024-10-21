#include<iostream>
using namespace std;

int mx = -1;
int x, y;

int main() {
    int tmp;
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin>>tmp;
            if(mx < tmp) {
                mx = tmp;
                y = i + 1;
                x = j + 1;
            }
        }
    }
    cout<<mx<<'\n';
    cout<<y<<' '<<x;
}