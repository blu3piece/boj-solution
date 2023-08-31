#include<iostream>
using namespace std;

int cache[10001];
int arr[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    for(int i = 1; i<=N; ++i) cin>>arr[i];
    cache[1] = arr[1];
    cache[2] = arr[2] + arr[1];
    for(int i = 3; i<=N; ++i) {
        cache[N] = max(arr[N] + arr[N - 1] + cache[N - 3], cache[N - 1]);
        cache[N] = max(cache[N], cache[N - 2] + arr[N]);
    }
    cout<<cache[N];
}