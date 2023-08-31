#include<iostream>
using namespace std;

int coins[10];

int main(){
    int N, K, cnt = 0; cin>>N>>K;
    for(int i=0; i<N; ++i){
        cin>>coins[i];
    }
    N--;
    while(K > 0){
        if(K >= coins[N]){
            cnt++;
            K -= coins[N];
        }
        else N--;
    }
    cout<<cnt;
}