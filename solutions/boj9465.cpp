#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001][2];
int cache[100001][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        for(int i = 1; i<=N; ++i) cin>>arr[i][0];
        for(int i = 1; i<=N; ++i) cin>>arr[i][1];
        // bottom-up 방식이 빠른 이유 : cache를 매번 초기화할 필요가 없음.
        cache[1][0] = arr[1][0];
        cache[1][1] = arr[1][1];
        cache[2][0] = cache[1][1] + arr[2][0];
        cache[2][1] = cache[1][0] + arr[2][1];
        for(int i = 3; i<=N; ++i){
            for(int j = 0; j<2; ++j) cache[i][j] = max(cache[i-1][j ^ 1], cache[i-2][j ^ 1]) + arr[i][j];
        }
        cout<<max(cache[N][0], cache[N][1])<<'\n';
    }
    return 0;
}