#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n; cin>>n;
    if(n == 1) {
        cout<<1;
        return 0;
    }
    if(n == 2) {
        cout<<2;
        return 0;
    }
    queue<int> q;
    for(int i=1; i<=n; ++i) {
        q.push(i);
    }
    q.pop();
    while(q.size() > 1) {
        q.push(q.front());
        q.pop();

        q.pop();
    }
    cout<<q.front();
}