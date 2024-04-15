#include<iostream>
#include<cstdlib>
using namespace std;

int arr[101];
int n, m;
int ans;

void f(int s, int cnt, int val) {
    if(cnt == 0) {
        if(m == val) {
            cout<<m;
            exit(0);
        }
        ans = ans < val ? val : ans;
        return;
    }
    for(int i=s; i<n; ++i) {
        int v = arr[i] + val;
        if(v > m) continue;
        f(i+1, cnt - 1, v);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    f(0, 3, 0);
    cout<<ans;
}