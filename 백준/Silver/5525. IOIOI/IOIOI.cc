#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s; cin>>n>>m;
    int ans = 0;
    int current_max = -1;
    bool was_i = false;
    string input;
    cin>>input;
    if(input[0] == 'I') {
        was_i = true;
        current_max = 0;
    }
    for(int i=1; i<m; ++i) {
        if(input[i] == 'I') {
            if(!was_i) {
                current_max++;
                if(current_max >= n) ans++;
            }    
            else current_max = 0;
            was_i = true;
        }
        if(input[i] == 'O') {
            if(!was_i) current_max = -1;
            was_i = false;
        }
    }
    cout<<ans;
}