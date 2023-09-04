#include<iostream>
#include<algorithm>
using namespace std;

int cache[1000001];

int main(){
    int N; cin>>N;
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;
    int ans;
    for(int i = 4; i<=N; ++i){
        ans = cache[i-1] + 1;
        if(!(i%3)) ans = min(ans, cache[i/3] + 1);
        if(!(i%2)) ans = min(ans, cache[i/2] + 1);
        cache[i] = ans;
    }
    cout<<cache[N];
    return 0;
}