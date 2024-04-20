#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq;


int main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        if(!x) {
            if(pq.empty()) {
                cout<<0<<'\n';
                continue;
            }
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else {
            pq.push(x);
        }
    }
}