#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    int N, K; cin>>N>>K;
    for(int i = 1; i<=N; ++i) q.push(i);
    cout<<'<';
    while(!q.empty()){
        for(int i = 0; i<K - 1; ++i){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout<<q.front();
        q.pop();
        if(!q.empty()) cout<<", ";
    }
    cout<<'>';
    return 0;
}