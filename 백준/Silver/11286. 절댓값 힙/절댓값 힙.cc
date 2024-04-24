#include<iostream>
#include<queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    while(n--) {
        int tmp; cin>>tmp;
        
        if(!tmp) {
            if(pq.empty()) {
                cout<<0<<'\n';
                continue;
            }
            cout<<pq.top().first * pq.top().second<<'\n';
            pq.pop();
        }
        
        if(tmp > 0) {
            pq.push({tmp, 1});
        }

        if(tmp < 0) {
            pq.push({-tmp, -1});
        }
    }
}