#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int cache[1001];

int solve(int s, int N){
    // LIS Starts from s.
    if(cache[s]) return cache[s];
    int ans = 0;
    for(int i = s + 1; i<=N; ++i){
        if(arr[s] < arr[i]) ans = max(ans, solve(i, N) + arr[i]);
    }
    cache[s] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    for(int i = 1; i<=N; ++i) cin>>arr[i];
    cout<<solve(0, N);
}