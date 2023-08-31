#include<iostream>
#include<string>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

bool isPrime[10001]; // 0 ~ 9999

void getPrime(){
    for(int i = 2; i<=10000; ++i) isPrime[i] = true;
    for(int i = 2; i*i<=10000; ++i){
        if(isPrime[i]) {
            for(int j=i*i; j<=10000; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int solve(int from, int to){
    bool visit[10000] = {false , };
    queue<pii> q;
    q.push(make_pair(from, 0));
    while(!q.empty()){
        pii node = q.front(); q.pop();
        visit[node.first] = true;

        if(node.first == to) return node.second;

        for(int i=1; i<=9; ++i){
            int tmp = stoi(to_string(i) + to_string(node.first).substr(1, 3));

            if(isPrime[tmp] && !visit[tmp])
                q.push(make_pair(tmp, node.second + 1));
        }
        for(int i=0; i<=9; ++i){
            int tmp = stoi(to_string(node.first).substr(0, 1) + to_string(i) + to_string(node.first).substr(2, 2));
            if(isPrime[tmp] && !visit[tmp]) q.push(make_pair(tmp, node.second + 1));
        }
        for(int i=0; i<10; ++i){
            int tmp = stoi(to_string(node.first).substr(0, 2) + to_string(i) + to_string(node.first).substr(3, 1));
            if(isPrime[tmp] && !visit[tmp]) q.push(make_pair(tmp, node.second + 1));
        }
        for(int i=0; i<10; ++i){
            int tmp = stoi(to_string(node.first).substr(0, 3) + to_string(i));
            if(isPrime[tmp] && !visit[tmp]) q.push(make_pair(tmp, node.second + 1));
        }
        
    }
    return -1;
}

int main(){
    int T; cin>>T;
    getPrime();
    while(T--){
        int from, to;
        cin>>from>>to;
        int tmp = solve(from, to);
        if(tmp == -1) cout<<"Impossible\n";
        else cout<<tmp<<'\n';
    }
}