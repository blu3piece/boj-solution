#include<iostream>
#include<cstring>
using namespace std;

bool visit[50];
int lotto[50];

int N;

void solve(int cnt, int prev){
    if(cnt == 6){
        for(int i=1; i<=49; ++i){
            if(visit[i] == true) cout<<i<<' ';
        }
        cout<<'\n';
    }
    for(int i=prev + 1; i<N; ++i){
        visit[lotto[i]] = true;
        solve(cnt + 1, i);
        visit[lotto[i]] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>N;
        if(N == 0) return 0;
        memset(lotto, 0, sizeof(lotto));
        for(int i=0; i<N; ++i){
            int tmp; cin>>tmp;
            lotto[i] = tmp;
        }
        solve(0, -1);
        cout<<'\n';
    }
}