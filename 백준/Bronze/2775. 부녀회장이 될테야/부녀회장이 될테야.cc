#include<iostream>
using namespace std;

int presum[15][15]; // i 층의 0 부터 j 층의 사람들의 합.
int value[15][15]; // i층 j호의 사람

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int i=1; i<=14; ++i) {
        value[0][i] = presum[0][i] = i;
        presum[0][i] += presum[0][i-1];
    }
    for(int i=1; i<=14; ++i) {
        for(int j=1; j<=14; ++j) {
            value[i][j] = presum[i][j] = presum[i-1][j];
            presum[i][j] += presum[i][j-1];
        }
    }
    while(t--) {
        int k, n; cin>>k>>n;
        cout<<value[k][n]<<'\n';
    }
}